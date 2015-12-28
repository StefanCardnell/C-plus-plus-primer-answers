#ifndef BULK_QUOTE
#define BULK_QUOTE

#include <string>
#include <iostream>
#include "Disk_Quote.h"


class Bulk_Quote : public Disk_Quote {
public:
    Bulk_Quote();
    Bulk_Quote(const std::string&, double, double, double);
    Bulk_Quote(const Bulk_Quote&);
    Bulk_Quote(Bulk_Quote&&) noexcept;
    Bulk_Quote& operator=(const Bulk_Quote&);
    Bulk_Quote& operator=(Bulk_Quote&&) noexcept;
    ~Bulk_Quote() override;

    Bulk_Quote* clone() const & override;
    Bulk_Quote* clone() && override;

    double net_price(size_t n) const override { return price*(n > min_qty ? (1-discount)*n : n);}

};


#endif // BULK_QUOTE
