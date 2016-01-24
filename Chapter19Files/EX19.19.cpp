//#define NDEBUG
//#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
//#include <string>
//#include <vector>
//#include <cstring> //c-style string functions
//#include <cstddef> //for size_t type and ptr_diff type
//#include <cctype> //for chararacter related functions
//#include <stdexcept> //Plain/Runtime/Logic exception classes
//#include <initializer_list> //for initializer_list type
//#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
//#include <cassert> //assert preprocessor macro
//#include <array>
//#include <list>
//#include <deque>
//#include <forward_list>
//#include <stack> //sequential container adaptor
//#include <queue> //sequential container adaptor, includes priority_queue
//#include <algorithm>
//#include <numeric> //more container algorithms
//#include <functional> //for bind library function (and ref/cref), and library defined function objects
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
//#include <memory> //for dynamic memory smart pointers
//#include <new> //nothrow and bad_alloc types, and allocator class
//#include <type_traits> //type transformation templates
//#include <tuple> //tuple class
//#include <bitset> //bitset class
//#include <regex> //regex library
//#include <random> //random-number engines and random-number distribution classes
//#include <ctime> //time function which is good in use with random generators
//#include <typeinfo> //bad_cast exception

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include "Sales_data.h"

int main(){

    /*Static member function was added to Sales_data to return pointer to average()*/

    /*The purpose of this question confuses me. 19.18 kind of required binding a member function pointer because
    we wanted to call empty() on each string but there is no other way to reference empty() for the third
    parameter of count_if when there is no object to call it from. In 19.19's case we need to compare the result
    of average() with a double, but by the stage of comparing there is an object we can call average() on - there
    is no need to use pointers or binds. For instance inside the lambda we could've just done p.average()
    (if average was public) rather than superfluously going through pointers and binds*/

    std::vector<Sales_data> v = {Sales_data("hello", 3, 1), Sales_data("hello", 3, 2), Sales_data("hello", 3, 3),
                                 Sales_data("hello", 3, 4), Sales_data("hello", 3, 5), Sales_data("hello", 3, 6),
                                 Sales_data("hello", 3, 7), Sales_data("hello", 3, 8), Sales_data("hello", 3, 9)
                                 };

    std::vector<Sales_data*> w;

    for(auto& c : v)
        w.push_back(&c);

    std::function<double (const Sales_data&)> f1 = Sales_data::returnAvg();
    std::function<double (const Sales_data*)> f2 = Sales_data::returnAvg();
    auto g = std::mem_fn(Sales_data::returnAvg());
    auto h = std::bind(Sales_data::returnAvg(), std::placeholders::_1);

    std::cout << *find_if(v.begin(), v.end(), [&f1](const Sales_data& p){ return f1(p) > 5;}) << std::endl;
    std::cout << **find_if(w.begin(), w.end(), [&f2](const Sales_data* p){ return f2(p) > 5;}) << std::endl;

    std::cout << *find_if(v.begin(), v.end(), [&g](const Sales_data& p){ return g(p) > 5;}) << std::endl;
    std::cout << **find_if(w.begin(), w.end(), [&g](const Sales_data* p){ return g(p) > 5;}) << std::endl;

    std::cout << *find_if(v.begin(), v.end(), [&h](const Sales_data& p){ return h(p) > 5;}) << std::endl;
    std::cout << **find_if(w.begin(), w.end(), [&h](const Sales_data* p){ return h(p) > 5;}) << std::endl;



}





