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

#include "Shape.h"



using namespace std;

class Base {
public:
    virtual int fcn() { cout << "Base::fcn()" << endl; return 0;};
};
class D1 : public Base {

public:
    int fcn() override { cout << "D1::fcn()" << endl; return 0;}
    virtual void f2() { cout << "D1::f2()" << endl; }
};

class D2 : public D1 {
public:
    int fcn(int) { cout << "D2::fcn(int)" << endl; return 0;}
    int fcn() override { cout << "D2::fcn()" << endl; return 0; }
    void f2() override { cout << "D2::f2()" << endl; }

};


int main(){


    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn(); //run-time bind, calls Base::fcn()
    bp2->fcn(); //run-time bind, calls D1::fcn()
    bp3->fcn(); //run-time bind, calls D2::fcn()
    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2->f2(); // error: Base has no member named f2
    d1p->f2(); //run-time bind, calls D1::f2()
    d2p->f2(); //run-time bind, calls D2::f2()

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    //p1->fcn(42); // error: Base has no version of fcn that takes an int
    //p2->fcn(42); // error: D1 has no verison of fcn that takes an int
    p3->fcn(42); // statically bound, calls D2::fcn(int)



}




