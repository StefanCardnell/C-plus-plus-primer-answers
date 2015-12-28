#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>


class Sales_data {
    friend std::ostream& print(std::ostream& os, const Sales_data& data);
    friend std::istream& read(std::istream& is, Sales_data& data);

public:
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(std::string s): Sales_data(s, 0, 0) { }
    Sales_data(std::string s, unsigned u, double p): bookNo(s), units_sold(u), revenue(u*p) { }
    Sales_data(std::istream& is): Sales_data() { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double average() const { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold;
    double revenue;

};


Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;

}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){

    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;

}

std::ostream& print(std::ostream& os, const Sales_data& data){

    os << data.isbn() << " " << data.units_sold << " " << data.revenue
       << " " << data.average();
    return os;

}

std::istream& read(std::istream& is, Sales_data& data){

    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price*data.units_sold;
    return is;

}

#endif // SALES_DATA
