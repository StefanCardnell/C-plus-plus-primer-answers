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

class Class {
public:
    Class() {std::cout << "Class default" << std::endl;}
    Class(const Class&) {std::cout << "Class copy" << std::endl;}
    Class(int){std::cout << "Class int" << std::endl;}
};

class Base : public Class {
public:
    Base() {std::cout << "Base default" << std::endl;}
    Base(const Base& b): Class(b) {std::cout << "Base copy" << std::endl;}
    Base(int i): Class(i) {std::cout << "Base int" << std::endl;}
};
class D1 : virtual public Base {
public:
    D1(): Base() {std::cout << "D1 default" << std::endl;}
    D1(const D1& d): Base(d) {std::cout << "D1 copy" << std::endl;}
    D1(int i): Base(i) {std::cout << "D1 int" << std::endl;}
};
class D2 : virtual public Base {
public:
    D2(): Base() {std::cout << "D2 default" << std::endl;}
    D2(const D2& d): Base(d) {std::cout << "D2 copy" << std::endl;}
    D2(int i): Base(i) {std::cout << "D2 int" << std::endl;}
};
class MI : public D1, public D2 {
public:
    MI(): Base(), D1(), D2() {std::cout << "MI default" << std::endl;}
    MI(const MI& d): Base(d), D1(d), D2(d) {std::cout << "MI copy" << std::endl;}
    MI(int i): Base(i), D1(i), D2(i) {std::cout << "MI int" << std::endl;}
};
class Final : public MI, public Class {
public:
    Final(): Base(), MI(), Class() {std::cout << "Final default" << std::endl;}
    Final(const Final& d): Base(d), MI(d) {std::cout << "Final copy" << std::endl;} //Can't use Class copy constructor: ambiguous Base
    Final(int i): Base(i), MI(i), Class(i) {std::cout << "Final int" << std::endl;}
};

int main(){

    MI(2);


}





