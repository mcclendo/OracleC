#ifndef WOODITEM_HPP
#define WOODITEM_HPP

#include "WoodCommon.hpp"

#include <string>

class WoodItem {
public:
	WoodItem(std::string& woodType, double baseDeliveryTimeInHours, uint32_t priceInCents);

    inline std::string getWoodType() const { return _woodType; }
    inline double getBaseDeliveryTimeInHours() const { return _baseDeliveryTimeInHours; }
    inline uint32_t getPriceInCents() const { return _priceInCents; }

private:

	std::string _woodType;
	double _baseDeliveryTimeInHours;
	uint32_t _priceInCents;
};
#endif
