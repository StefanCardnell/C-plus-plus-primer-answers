#ifndef DISK_QUOTE
#define DISK_QUOTE

#include "Quote.h"

class Disk_Quote : public Quote {
public:
    Disk_Quote() = default;
    Disk_Quote(const std::string& b, double p, double q, double d): Quote(b,p), min_qty(q), discount(d) { }

    double net_price(size_t) const override = 0;
    Quote* clone() const & override = 0;
    Quote* clone() && override = 0;
    void debug() const override { Quote::debug(); std::cout << "| min_qty: " << min_qty << "| discount: " << discount;}

protected:
    size_t min_qty = 0;
    double discount = 0.0;

};

#endif // DISK_QUOTE
