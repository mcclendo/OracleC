#include "WoodOrderManager.hpp"

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

static double calculateDeliveryTimeMultiplier(uint32_t bf) {
    double multiplier = 0;
    if(bf <= 100)
        multiplier = 1;
    else if(bf <= 200)
        multiplier = 2;
    else if(bf <= 300)
        multiplier = 3;
    else if(bf <= 400)
        multiplier = 4;
    else if(bf <= 500)
        multiplier = 5;
    else if(bf <= 1000)
        multiplier = 5.5;
    else
        throw WoodOrderManagerException("Board Feet must be <= 1000.");
}

WoodOrderManager::WoodOrderManager() : _orders() {
    std::vector<WoodItem> tempItems{ 
        { "Cherry",           2.5, 595 },
        { "Curry Maple",      1.5, 600 },
        { "Genuine Mahogany", 3,   960 },
        { "Wenge",            5,   2235},
        { "White Oak",        2.3, 670 },
        { "Sawdust",          1,   150 }
    };

    for(auto& w : tempItems) {
        _woodItems[w.getWoodType()] = w;
    }
}

void WoodOrderManager::initializeData(const std::string& inputFile) {
    std::ifstream ifs;
    std::string line;

    std::vector<std::string> tokens;
    ifs.open(inputFile);

    auto lambda = [](const std::string& line, 
                     const std::string& delim, 
                     std::vector<std::string>& tokens) {
        std::string token;
        size_t startIndex = 0;
        size_t endIndex = line.find(delim);

        while(endIndex != std::string::npos) {
            token = line.substr(startIndex, endIndex - startIndex);
            tokens.push_back(token);

            startIndex = endIndex + delim.length();
            endIndex = line.find(delim, startIndex);
        }

        tokens.push_back(line.substr(startIndex, endIndex));
    };

    if(ifs.is_open()) {
        std::string orderDelim(";");
        std::string itemDelim(":");
        std::string token;

        while(std::getline(ifs, line)) {
            tokens.clear();

            lambda(line, orderDelim, tokens);

            std::unique_ptr<WoodOrder> order(new WoodOrder(tokens[0], tokens[1], tokens[2]));
            tokens.clear();

            std::getline(ifs, line);
            lambda(line, orderDelim, tokens);

            for(auto& item : tokens) {
                std::vector<std::string> itemTokens;
                lambda(item, itemDelim, itemTokens);

                if(_woodItems.count(itemTokens[0]) == 0)
                    throw WoodOrderManagerException("Unknown wood type '" + itemTokens[0] + "'.");

                order->addItem(itemTokens[0], std::stoi(itemTokens[1], nullptr));
            }


            _orders.push_back(std::move(order));
        }
    }
    else {
        throw WoodOrderManagerException("Could not open input file '" + inputFile + ".");
    }
}

void WoodOrderManager::orderReport(std::stringstream &ss) const {
    uint32_t orderNum = 1;

    auto dollars = [](uint32_t cents) {
        std::string r("$");

        if(cents < 100) {
            r += "0.";
            if(cents < 10) 
                r += "0";
            r += cents;
        }
        else {
            auto s = std::to_string(cents);
            uint32_t wholeDollars = cents/100;
            r += std::to_string(wholeDollars) + "." + s.substr(s.length()-2, 2);
        }

        return r;
    };

    ss << "#### Begin Report ####" << std::endl;
    std::string orderSeparator("---------------------------------------------------------");
    for(auto& order : _orders) {
        uint32_t totalPriceInCents = 0;
        ss << "Order #" << orderNum++ << std::endl
            << orderSeparator << std::endl
            << "Customer: " << order->getCustomerName() << std::endl
            << "Address: " << order->getAddress() << std::endl
            << "Date: " << order->getDate() << std::endl;;

        uint32_t itemNumber = 1;
        order->forEach([&](const WoodOrderDetail &detail) {
            auto price = (uint32_t)detail.getBoardFeet() * _woodItems.at(detail.getWoodType()).getPriceInCents();
            ss << "  Item #" << itemNumber++ << " [" << detail.getWoodType() << "] - " << detail.getBoardFeet() 
               << "BF - " << dollars(price) << std::endl;

            totalPriceInCents += price;
        });

        ss << std::endl << "Total: " << dollars(totalPriceInCents) << std::endl 
            << "Estimated Delivery Time: " << getOrderDeliveryTime(*order) << " hrs" << std::endl << orderSeparator << std::endl << std::endl;;
    }
    ss << "#### End Report ####" << std::endl;
}

double WoodOrderManager::getOrderDeliveryTime(const WoodOrder &order) const {
    double deliveryTime = 0;

    order.forEach([&](const WoodOrderDetail &detail) {
        deliveryTime = std::max(deliveryTime, getOrderDetailDeliveryTime(detail));
    });

    return deliveryTime;
}

double WoodOrderManager::getOrderDetailDeliveryTime(const WoodOrderDetail &detail) const {
    auto deliveryTimeMultiplier = calculateDeliveryTimeMultiplier(detail.getBoardFeet());

    return _woodItems.at(detail.getWoodType()).getBaseDeliveryTimeInHours() * deliveryTimeMultiplier;
}
