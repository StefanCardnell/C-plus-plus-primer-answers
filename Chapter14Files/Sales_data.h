#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>


class Sales_data {
    friend std::istream& read(std::istream& is, Sales_data& data);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(std::string s): Sales_data(s, 0, 0) { }
    Sales_data(std::string s, unsigned u, double p): bookNo(s), units_sold(u), revenue(u*p) { }
    Sales_data(std::istream& is): Sales_data() { read(is, *this); }

    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const std::string&);

    std::string isbn() const { return bookNo; }

private:
    double average() const { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold;
    double revenue;

};

std::ostream& operator<<(std::ostream&, const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);


#endif // SALES_DATA
