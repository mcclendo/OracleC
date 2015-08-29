#ifndef WOOD_ORDER_MANAGER_HPP
#define WOOD_ORDER_MANAGER_HPP

#include "WoodOrder.hpp"

#include <vector>
#include <memory>

class WoodOrderManager {
public:
    WoodOrderManager();

    void intializeData(std::string& data);
private:
    std::vector<std::unique_ptr<WoodOrder>> _orders;
};
#endif
