//#define NDEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include "Sales_data.h"


//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;




int main(int argc, char* argv[]){

    if(argc > 1){
        ifstream input(argv[1]);
        if(input){
            Sales_data total;
            if (read(input, total)) {
                Sales_data trans;
                while(read(input, trans)) {
                    if (total.isbn() == trans.isbn())
                        total.combine(trans);
                    else {
                        print(cout, total) << endl;
                        total = trans;
                    }
                }
                print(cout, total) << endl;
            }
            else cerr << "No data?!" << endl;
        }
        else cerr << string("Failed to open ") + argv[1] << endl;
    }
    else cerr << "File name was not passed?" << endl;

/*remember to place notepad document in C:\Users\Stefan when
  running from command line*/



}










