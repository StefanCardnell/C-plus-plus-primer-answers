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

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;


string& replacefunction(string& s, string oldVal, string newVal){

    for(auto pos = s.begin(); pos != (s.end()-oldVal.size()+1);)
        if(string(pos, pos+oldVal.size()) == oldVal){
            pos = s.erase(pos, pos+oldVal.size());
            pos = s.insert(pos, newVal.begin(), newVal.end());
            pos += newVal.size();
        }
        else ++pos;

    return s;


}



int main(){

    string s = "wassup" , oldVal = "tho", newVal = "though";

    replacefunction(s, oldVal, newVal);

    cout << s << "."; //CAN'T RUN THIS PROGRAM SINCE ITERATOR RETURN FEATURE ISN'T SUPPORTED




}










