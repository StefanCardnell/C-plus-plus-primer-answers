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





int main(){

    vector<string> jonSnow = {"-42", "+8924", "0192", "-91820"};

    int totalsum1 = 0;

    for(auto c : jonSnow)
        totalsum1 += stoi(c);


    cout << totalsum1 << endl;





    vector<string> daenerys = {"42.1", "8e2", ".12", "-2.2E1"};

    double totalsum2 = 0;

    for(auto c : daenerys)
        totalsum2 += stod(c);

    cout << totalsum2 << endl;


}










