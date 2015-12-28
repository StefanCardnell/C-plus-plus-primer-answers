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


using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz){
    return s.size() >= sz;
}

void find_first_greater(const std::vector<int>& v1, const std::string& s1){

    auto lambda = [&](int i){ return (i < 0 ? false : !check_size(s1, i));};

    auto it = find_if(v1.begin(), v1.end(), lambda);

    std::cout << *it;

}

int main()
{
    std::vector<int> i1 = {1,2,3,-4,1,0,5,7,7,3,0,2,4};

    std::string s1 = "hello!";

    find_first_greater(i1, s1);



}









