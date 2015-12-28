//#define NDEBUG
#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
#include <cstring> //c-style string functions
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
//#include <functional> //for bind library function (and ref/cref)
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)


using namespace std;

int main(){

    /*string s;

    cout << "Enter the string: ";
    getline(cin, s);

    char* p = new char[s.size()+1]();

    strcat(p, s.c_str());

    cout << p;

    delete [] p;*/

    //while this could be what it wants, it seems superfluous
    //to store it in a string (which is basically a dynamic char array)
    //and then store it back in to a separate dynamic array
    //Better to avoid the use of a string


    char* p = new char[255];

    cout << "Enter your string: ";

    cin.getline(p, 255);

    cout << p;

    delete [] p;

    //in this case it takes 10 characters from the input stream, if any more
    //are entered then the rest are ignored. Note that p actually stores
    //9 characters and a null.

    //We could ask the user what size they will be entering and adjust the dynamic
    //array size based on this. This was not what was asked.








}










