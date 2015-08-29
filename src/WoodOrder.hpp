#ifndef WOOD_ORDER_HPP
#define WOOD_ORDER_HPP

#include "WoodCommon.hpp"
#include "WoodOrderDetail.hpp"

#include <functional>
#include <memory>
#include <vector>

class WoodOrder {
public:
    WoodOrder(std::string& customerName, std::string& address, std::string& date);

    inline std::string getCustomerName() const { return _customerName; }
    inline std::string getAddress() const { return _address; }
    inline std::string getDate() const { return _date; }

    void addItem(WoodItem& woodItem, uint32_t quantity);
    inline uint32_t itemCount() const { return static_cast<uint32_t>(_lineItems.size()); }
    void forEach(std::function<void(const WoodOrderDetail&)> iteratorFn) const;

private:
    std::string _customerName;
    std::string _address;
    std::string _date;

    std::vector<std::unique_ptr<WoodOrderDetail>> _lineItems;
};
#endif
