#include "Sales_data.h"
#include <iostream>

using namespace std;

Sales_data& Sales_data::operator+=(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator=(const string& rhs){
    *this = Sales_data(rhs);
    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs){
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& data){
    os << data.isbn() << " " << data.units_sold << " " << data.revenue
       << " " << data.average();
    return os;
}

std::istream& operator>>(std::istream& is, Sales_data& data){
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    if(is)
        data.revenue = price*data.units_sold;
    else
        data = Sales_data();
    return is;
}
