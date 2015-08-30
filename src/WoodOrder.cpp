#include "WoodOrder.hpp"

WoodOrder::WoodOrder(std::string& customerName, std::string& address, std::string& date)
    : _customerName(customerName), _address(address), _date(date), _lineItems() {

}

void WoodOrder::addItem(const std::string& woodType, uint32_t quantity) {
    std::unique_ptr<WoodOrderDetail> item(new WoodOrderDetail(woodType, quantity));

    _lineItems.push_back(std::move(item));
}

void WoodOrder::forEach(std::function<void(const WoodOrderDetail&)> iteratorFn) const {
    for(const auto& w : _lineItems) {
        iteratorFn(*w);
    }
}
