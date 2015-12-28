//#define NDEBUG
#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;


struct Sales_data {
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double average() const { return revenue/units_sold; }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

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

int main(){

    Sales_data total;

    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else{
        cerr << "No data?!" << endl;
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;

}






