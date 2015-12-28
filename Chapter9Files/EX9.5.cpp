//#define NDEBUG
#include <iostream>
#include <fstream>
#include <sstream> //stringstream
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro


//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;

vector<int>::iterator test(vector<int>::iterator ibegin, vector<int>::iterator iend, int x){

    while(ibegin != iend){
        if(*ibegin == x)
            return ibegin;
        else ++ibegin;
    }

    return iend;


}



int main(){


    int x = 2;

    const int& y = x;

    const int& f = y;




}










