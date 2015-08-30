#include "WoodItem.hpp"

WoodItem::WoodItem() : _woodType(), _baseDeliveryTimeInHours(0), _priceInCents(0) {

}

WoodItem::WoodItem(std::string woodType, double baseDeliveryTimeInHours, uint32_t priceInCents) 
    : _woodType(woodType),
      _baseDeliveryTimeInHours(baseDeliveryTimeInHours),
      _priceInCents(priceInCents) {

}

