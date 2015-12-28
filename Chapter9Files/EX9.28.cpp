//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <string>
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


//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;

void testfunction(forward_list<string>& a, string b, string c){

    auto prev = a.before_begin();

    for(auto curr = a.begin(); curr != a.end(); prev = curr++)
        if(*curr == b){
            a.insert_after(curr, c);
            return;
        }

    a.insert_after(prev, c);
    return;

}




int main(){

    forward_list<string> a = {"hello", "mother", "fuckers"};

    testfunction(a, "mother", "of");

    for(auto c : a)
        cout << c << " ";




}










