#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>
#include <stdexcept>

namespace std{
    template <typename T> struct hash;
}

class Sales_data {
    typedef double(Sales_data::* avg)() const;
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend class std::hash<Sales_data>;

public:

    static avg returnAvg() { return &Sales_data::average;}

    /* All constructors are delegating except one. This non-delegating constructor cannot possibly throw*/

    Sales_data() noexcept : Sales_data("", 0, 0) { }
    Sales_data(std::string s) noexcept : Sales_data(s, 0, 0) { }
    Sales_data(std::string s, unsigned u, double p) noexcept : bookNo(s), units_sold(u), revenue(u*p) { }
    Sales_data(std::istream& is) noexcept : Sales_data() { is >> *this; }

    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const std::string&);

    std::string isbn() const { return bookNo; }

private:
    double average() const { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold;
    double revenue;

};

namespace std{

    template <> struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data&) const;
    };

}

std::ostream& operator<<(std::ostream&, const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);




class out_of_stock : public std::runtime_error{
public:
    explicit out_of_stock(const std::string& s): std::runtime_error(s) { }
};

class isbn_mismatch : public std::logic_error{
public:
    explicit isbn_mismatch(const std::string& s): std::logic_error(s) { }
    isbn_mismatch(const std::string& s, const std::string& l, const std::string& r): std::logic_error(s), left(l), right(r) { }
    const std::string left, right;
};




#endif // SALES_DATA
