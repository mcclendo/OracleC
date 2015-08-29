#ifndef WOOD_ORDER_DETAIL_HPP
#define WOOD_ORDER_DETAIL_HPP

#include "WoodCommon.hpp"
#include "WoodItem.hpp"

class WoodOrderDetail {
public:
    WoodOrderDetail(WoodItem &woodItem, uint32_t quantity);

    inline uint32_t getQuantity() const { return _quantity; }
    inline WoodItem getWoodItem() const { return _woodItem; }
private:
    WoodItem _woodItem;
    uint32_t _quantity;
};
#endif
