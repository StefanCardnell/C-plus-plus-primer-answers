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
#include <utility> //for pair library type (used in map associative container), also for std::move
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class


//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include "Quote.h"
#include "Disk_Quote.h"
#include "Bulk_Quote.h"
#include "Limited_Quote.h"

using namespace std;


class Base{ void memfcn(Base &b) { b = *this; }};

class Pub_Derv : public Base { void memfcn(Base &b) { b = *this; }};

class Priv_Derv : private Base { void memfcn(Base &b) { b = *this; }};

class Prot_Derv : protected Base { void memfcn(Base &b) { b = *this; }};

class Derived_from_Public : public Pub_Derv { void memfcn(Base &b) { b = *this; }};

class Derived_from_Priv : public Priv_Derv { };

class Derived_from_Prot : public Prot_Derv { void memfcn(Base &b) { b = *this; }};

int main(){

Pub_Derv d1;
Base *p = &d1; // d1 has type Pub_Derv

//Priv_Derv d2;
//p = &d2; // d2 has type Priv_Derv

//Prot_Derv d3;
//p = &d3; // d3 has type Prot_Derv

Derived_from_Public dd1;
p = &dd1; // dd1 has type Derived_from_Public

//Derived_from_Priv dd2;
//p = &dd2; // dd2 has type Derived_from_Private

//Derived_from_Prot dd3;
//p = &dd3; // dd3 has type Derived_from_Protected





}




