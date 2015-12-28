//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <string>
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


//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;



int main(){

    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> vec(begin(ia), end(ia));
    list<int> lis(begin(ia), end(ia));



    for(auto i = vec.begin(); i != vec.end(); )
        if((*i)%2 == 0) i = vec.erase(i);
        else ++i;

    for(auto i = lis.begin(); i != lis.end(); )
        if((*i)%2 == 1) i = lis.erase(i);
        else ++i;

    for(auto c : vec)
        cout << c << " ";

    cout << endl;

    for(auto c : lis)
        cout << c << " ";

    cout << endl;




}










