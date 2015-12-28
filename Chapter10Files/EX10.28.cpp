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
#include "Sales_data.h"

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)


int main(){

    std::vector<int> v1 = {1,2,3,4,5,6,7,8,9};

    std::list<int> l1, l2, l3;

    copy(v1.begin(), v1.end(), front_inserter(l1));

    for(auto c : l1)
        std::cout << c << " ";
    std::cout << std::endl;

    copy(v1.begin(), v1.end(), back_inserter(l2));

    for(auto c : l2)
        std::cout << c << " ";
    std::cout << std::endl;

    copy(v1.begin(), v1.end(), inserter(l3, l3.end()));

    for(auto c : l3)
        std::cout << c << " ";
    std::cout << std::endl;

}









