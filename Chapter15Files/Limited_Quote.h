#ifndef LIMITED_QUOTE
#define LIMITED_QUOTE

#include <string>
#include "Disk_Quote.h"

class Limited_Quote : public Disk_Quote {
public:
    Limited_Quote() = default;
    Limited_Quote(const std::string& b, double p, double q, double d): Disk_Quote(b, p, q, d) { }

    double net_price(size_t n) const override { return price*(n <= min_qty ? ((1-discount)*n) : (n-min_qty) + (1-discount)*min_qty);}

};


#endif // BULK_QUOTE
