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
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;



int main(){

    vector<int> x = {1,2,3,4,5,6,7,8,9,10,11};

    cout << accumulate(x.begin(), x.end(), 0) << endl;

    vector<double> y = {1.1,2.2,3.3,4.4};

    cout << accumulate(y.begin(), y.end(), 0) << endl;

    //0 is an integer literal, all the numbers in the vector
    //gets truncated before summation. Better to use 0.0 or .0

    vector<double> z = {1.1,2.2,3.3,4.4};

    cout << accumulate(z.begin(), z.end(), .0) << endl;








}










