#ifndef WOOD_ORDER_MANAGER_HPP
#define WOOD_ORDER_MANAGER_HPP

#include "WoodOrder.hpp"

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>

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
#endif
