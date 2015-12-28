#ifndef QUOTE
#define QUOTE

#include <string>
#include <iostream>

class Quote{

public:
    Quote();
    Quote(const std::string&, double);
    Quote(const Quote&);
    Quote(Quote&&) noexcept;
    Quote& operator=(const Quote&);
    Quote& operator=(Quote&&) noexcept;
    virtual ~Quote();

    virtual Quote* clone() const &;
    virtual Quote* clone() &&;
    std::string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const { return (price*n); }
    virtual void debug() const { std::cout << "|bookNo: " << bookNo << "| price: " << price;}
private:
    std::string bookNo;
protected:
    double price = 0.0;

};

#endif // QUOTE
