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

class Base1{
public:
    virtual void print() {std::cout << "Base1::print()" << std::endl;}
    virtual ~Base1() { std::cout << "Base1::~Base1()" << std::endl;}
};

class Base2{
public:
    virtual void print() {std::cout << "Base2::print()" << std::endl;}
    virtual ~Base2() { std::cout << "Base2::~Base2()" << std::endl;}
};

class D1 : public Base1{
public:
    virtual void print() {std::cout << "D1::print()" << std::endl;}
};
class D2 : public Base2{
public:
    virtual void print() {std::cout << "D2::print()" << std::endl;}
};

class MI : public D1, public D2{
public:
    virtual void print() {std::cout << "MI::print()" << std::endl;}
};

int main(){

Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
pb1->print();
pd1->print();
pd2->print();
delete pb2;
delete pd1;
delete pd2;


}





