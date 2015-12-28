//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <cctype> //for chararacter related functions
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
#include <functional> //for bind library function
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
#include <unordered_map> //for unordered_map and unordered_multimap
#include <unordered_set> //for unordered_set and unordered_multiset
#include <utility> //for pair library type (used in map associative container)
#include "Sales_data.h"
#include <typeinfo>

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;


int main(){

    multimap<string, string> authors = {{"George R.R. Martin", "A Game of Thrones"}, {"George R.R. Martin", "A Clash of Kings"},
                                       {"George R.R. Martin", "A Storm of Swords"}, {"George R.R. Martin", "A Feast for Crows"},
                                       {"Stephen King", "IT"}, {"George Orwell", "Animal Farm"}, {"George Orwell", "1984"},
                                       {"F. Scott. Fitzgerald", "The Great Gatsby"}};

    string desireAuth = "George R.R. Martin", desireBook = "A Game of Thrones";

    auto start = authors.find(desireAuth);
    auto count = authors.count(desireAuth);

    while(count){
        if(start->second == desireBook){
            authors.erase(start);
            break;
        }

        ++start;
        --count;

    }



    for(const auto& c : authors)
        cout << c.first << ": " << c.second << endl;




}










