//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <cctype> //for chararacter related functions
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms
#include <functional> //for bind library function (and ref/cref), and library defined function objects
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
#include <unordered_map> //for unordered_map and unordered_multimap
#include <unordered_set> //for unordered_set and unordered_multiset
#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class
#include <type_traits> //type transformation templates
//
//
////difference_type (iterator arithmetic) and ::size_type are for strings/vectors
////ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)
//
////-c is for separate compilation (creates .o object files)
////-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
////-std=c++11 for C++11 support

using namespace std;

//i)
//
//sizeof...(Args) = 3
//sizeof...(rest) = 3
//
//ii)
//
//sizeof...(Args) = 2
//sizeof...(rest) = 2
//
//iii)
//
//sizeof...(Args) = 1
//sizeof...(rest) = 1
//
//iv)
//
//sizeof...(Args) = 0
//sizeof...(rest) = 0

template <typename T, typename... Args> void foo(const T& t, const Args& ... rest){
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main(){

    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d); // three parameters in the pack
    foo(s, 42, "hi"); // two parameters in the pack
    foo(d, s); // one parameter in the pack
    foo("hi"); // empty pack


}












