#ifndef WOOD_ORDER_DETAIL_HPP
#define WOOD_ORDER_DETAIL_HPP

#include "WoodCommon.hpp"
#include "WoodItem.hpp"

class WoodOrderDetail {
public:
    WoodOrderDetail(const std::string &woodType, uint32_t bf);

    inline uint32_t getBoardFeet() const { return _bf; }
    inline std::string getWoodType() const { return _woodType; }
private:
    std::string _woodType;
    uint32_t _bf;
};
#endif
