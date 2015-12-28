#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>

using namespace std;


class Sales_data {
    friend ostream& print(ostream& os, const Sales_data& data);
    friend istream& read(istream& is, Sales_data& data);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(string s): Sales_data(s, 0, 0) { }
    Sales_data(string s, unsigned u, double p): bookNo(s), units_sold(u), revenue(u*p) { }
    Sales_data(istream& is): Sales_data() { read(is, *this); }

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    inline double average() const { return units_sold ? revenue/units_sold : 0; }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

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

ostream& print(ostream& os, const Sales_data& data){

    os << data.isbn() << " " << data.units_sold << " " << data.revenue
       << " " << data.average();
    return os;

}

istream& read(istream& is, Sales_data& data){

    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price*data.units_sold;
    return is;

}

#endif // SALES_DATA
