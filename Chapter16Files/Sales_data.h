#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>

namespace std{
    template <typename T> struct hash;
}

class Sales_data {
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend class std::hash<Sales_data>;

public:
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(std::string s): Sales_data(s, 0, 0) { }
    Sales_data(std::string s, unsigned u, double p): bookNo(s), units_sold(u), revenue(u*p) { }
    Sales_data(std::istream& is): Sales_data() { is >> *this; }

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


#endif // SALES_DATA
