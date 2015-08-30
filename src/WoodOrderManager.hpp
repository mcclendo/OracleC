#ifndef WOOD_ORDER_MANAGER_HPP
#define WOOD_ORDER_MANAGER_HPP

#include "WoodOrder.hpp"

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stdexcept>

class WoodOrderManager {
public:
    WoodOrderManager();

    void initializeData(const std::string& inputFile);

    double getOrderDeliveryTime(const WoodOrder &order) const;
    double getOrderDetailDeliveryTime(const WoodOrderDetail &detail) const;

    void orderReport(std::stringstream &ss) const;
private:
    std::vector<std::unique_ptr<WoodOrder>> _orders;
    std::map<std::string, WoodItem> _woodItems;

};

struct WoodOrderManagerException : public std::runtime_error {
    WoodOrderManagerException(const std::string& msg) : std::runtime_error(msg){};
};
#endif
