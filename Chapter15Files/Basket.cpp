#include "Basket.h"

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

void Basket::addItem(const Quote& sale){
    items.insert(shared_ptr<Quote>(sale.clone()));
}

void Basket::addItem(Quote&& sale){
    items.insert(shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt(ostream& os) const {
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total price: " << sum << endl;
    return sum;
}
