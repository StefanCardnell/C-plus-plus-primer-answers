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
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};


int main(){

    Sales_data total;

    if(cin >> total.bookNo >> total.units_sold >> total.revenue){
        total.revenue *= total.units_sold;
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if(total.bookNo == trans.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += (trans.revenue*trans.units_sold);
            }
            else{
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue
                     << " " << total.revenue/total.units_sold << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.units_sold*trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue
                     << " " << total.revenue/total.units_sold << endl;
    }
    else{
        cerr << "No data?!" << endl;
    }


}





