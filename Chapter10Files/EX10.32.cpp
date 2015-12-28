//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <string>
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms
#include <functional> //for bind library function
#include "Sales_item.h"

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)


int main(){

    std::vector<Sales_item> sum;

    std::ifstream input("test.txt");

    if(!input){
        std::cout << "Failed to open file. Exiting." << std::endl;
        return EXIT_FAILURE;
    }

    std::istream_iterator<Sales_item> iter_istr(input), eof;
    std::ostream_iterator<Sales_item> iter_ostr(std::cout, "\n");

    while(iter_istr != eof)
        sum.push_back(*iter_istr++);

    sort(sum.begin(), sum.end(), compareIsbn); //requires changing sales_item compareIsbn function to < rather than ==

    for(auto it1 = sum.cbegin(), it2 = it1; it1 != sum.end(); it1 = it2){
        it2 = find_if(it1, sum.cend(), [it1](const Sales_item& s){return s.isbn() != it1->isbn();});
        *iter_ostr++ = accumulate(it1, it2, Sales_item(it1->isbn()));
    }
}









