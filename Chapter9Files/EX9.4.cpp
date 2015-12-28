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

bool test(vector<int>::const_iterator ibegin, vector<int>::const_iterator iend, int x){

    while(ibegin != iend){
        if(*ibegin == x)
            return true;
        else ++ibegin;
    }

    return false;


}


int main(){

    vector<int> x = {2,3,4,5};

    cout << test(x.begin(), x.end(), 3);


}










