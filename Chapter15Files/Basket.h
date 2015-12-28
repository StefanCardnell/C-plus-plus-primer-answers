#ifndef BASKET
#define BASKET

#include <set>
#include <istream>
#include <memory>
#include "Quote.h"



class Basket{
public:
    void addItem(const Quote&);
    void addItem(Quote&&);
    double total_receipt(std::ostream&) const;

private:
    static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare}; //in-class initialisers cannot be parentheses

};

#endif // BASKET




