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
#include "Sales_data.h"

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;


void elimDups(vector<string>& v){

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());


}

void biggies(vector<string>& words, string::size_type sz){
    elimDups(words);

    stable_sort(words.begin(), words.end(), [](const string& s1, const string& s2){ return s1.size() < s2.size();});


    cout << count_if(words.begin(), words.end(), [=](const string &s1){ return s1.size() >= sz;}) << " words found with size greater than/equal to " << sz << " and they are:" << endl;

    auto it = find_if(words.begin(), words.end(), [sz](const string& s1){ return s1.size() >= sz;});
    for_each(it, words.end(), [](const string& s1){ cout << s1 << " ";});

}




int main(){


    vector<string> words = {"the", "quick", "fucking", "brown", "fox", "jumped", "over", "the", "lazy", "reddish", "dog"};


    biggies(words, 2);

}









