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


//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;

unordered_map<string, string> transformPhrase(ifstream& phrases){

    unordered_map<string, string> replacements;

    for(string word, phrase; phrases >> word && getline(phrases, phrase); ){
        if(phrase.size() > 1) replacements[word] = phrase.substr(1);
        else throw runtime_error("No phrase supplied for " + word);
    }

    return replacements;

}

const string& returnTransformed(const string& s, const unordered_map<string, string>& m){ //we can declare map as const since we aren't using subscript

    auto it = m.find(s);

    if(it == m.cend()) return s;
    else return it->second;


}

void fileTransform(ifstream& phrases, ifstream& input){

    auto replacements = transformPhrase(phrases);

    for(string temp; getline(input, temp);){
        istringstream line(temp);
        bool linestart = true;

        for(string word; line >> word;){
            cout << (linestart ? "" : " ") << returnTransformed(word, replacements);
            linestart = false;
        }
        cout << endl;
    }

}


int main(){

    ifstream input("input.txt"), phrases("phrases.txt");

    if(!input || !phrases){
        cout << "File couldn't be opened" << endl;
        return EXIT_FAILURE;
    }

    fileTransform(phrases, input);


}










