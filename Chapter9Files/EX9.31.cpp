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






int main(){


    list<int> lis = {0,1,2,3,4,5,6,7,8,9};

    for(auto iter = lis.begin(); iter != lis.end(); ) {
        if (*iter % 2) {
            lis.insert(iter, *iter);
            ++iter;
        } else
        iter = lis.erase(iter);
    }




    forward_list<int> flis = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flis.before_begin();

    for(auto curr = flis.begin(); curr != flis.end();)
        if (*curr % 2){
            flis.insert_after(prev, *curr);
            prev = curr++;
        }
        else curr = flis.erase_after(prev);





}










