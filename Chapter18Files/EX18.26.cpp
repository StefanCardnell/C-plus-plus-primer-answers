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

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support


#include <iostream>
#include <string>
#include <vector>

struct Base1 {
    void print(int) const { std::cout << "Int" << std::endl;} // public by default
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};
struct Base2 {
    void print(double) const { std::cout << "Double" << std::endl;} // public by default
protected:
    double fval;
private:
    double dval;
};
struct Derived : public Base1 {
    using Base1::print;
    void print(std::string) const { std::cout << "String" << std::endl;} // public by default
protected:
    std::string sval;
    double dval;
};
struct MI : public Derived, public Base2 {
    using Derived::print;
    using Base2::print;
    void print(std::vector<double>) { std::cout << "Vector" << std::endl;} // public by default
protected:
    int *ival;
    std::vector<double> dvec;
};

int main(){

    MI mi;
    mi.print(42);

    /*Problem previously: name lookup finds and stops at print(std::vector<double>) declared in MI definition
    so it attempts to create a vector from the integer literal 42, which is not possible. The intent
    of the user might be to access void print(int) from Base1. Solutions include:

    1) Using declarations to bring the prints in to scope of MI
    2) Defining our own version of print(int) in MI to use Base::print(int) which IMO is too laborious.
    3) Explicitly call the print from Base1 (i.e. mi.Base1::print(42))*/


}





