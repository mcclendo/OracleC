#include "WoodItem.hpp"

WoodItem::WoodItem(std::string& woodType, double baseDeliveryTimeInHours, uint32_t priceInCents) 
    : _woodType(woodType),
      _baseDeliveryTimeInHours(baseDeliveryTimeInHours),
      _priceInCents(priceInCents) {

}

