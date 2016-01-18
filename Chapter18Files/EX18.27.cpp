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
    double dval = 2;
    char cval;
private:
    int *id;
};
struct Base2 {
    void print(double) const { std::cout << "Double" << std::endl;} // public by default
protected:
    double fval = 10;
private:
    double dval = 5;
};
struct Derived : public Base1 {
    void print(std::string) const { std::cout << "String" << std::endl;} // public by default
protected:
    std::string sval = "hello";
    double dval = 10;
};
struct MI : public Derived, public Base2 {
    void print(std::vector<double>) { std::cout << "Vector" << std::endl;}
    void foo(double cval); // public by default
protected:
    int *ival;
    std::vector<double> dvec{3,2,4};
};

int ival;
double dval;
void MI::foo(double cval){
    int dval = Base1::dval + Derived::dval;
    std::cout << dval << std::endl;

    fval = dvec.back();
    std::cout << fval << std::endl;

    Base1::cval = sval[0];
    std::cout << Base1::cval << std::endl;

}

int main(){

    MI m;

    m.foo(2.);

    /* (a):

    FIRST: Local scope:

    1. The parameter cval is visible.
    2. The local variable dval is visible.

    SECOND: Class (MI scope):

    1. The int* ival in scope MI is visible.
    2. The vector<double> dvec in scope MI is visible.
    3. void print(vector<double>) function is visible.

    THIRD: Base class scopes:

        dval, ival, cval are hidden by inner scopes.
        int* id not visible since it is private

        DERIVED:

        1. string sval is visible

        BASE2:

        1. double fval is visible

    FOURTH: Global scope.

    ival and dval from global scope have been hidden.


    (b):

    At the point in which the exercise occurs, no. We don't have to worry about
    any potential ambiguity when we use unqualified names with foo. When choosing
    the base classes potential ambiguities could have come from dval or print,
    however print gets redefined in MI and dval gets its name hidden in the local
    scope of foo.*/








}





