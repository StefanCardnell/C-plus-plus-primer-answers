//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
//#include <cstring> //c-style string functions
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
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support


using namespace std;



int main(){


    ifstream input("test.txt");
    if(!input){
        cout << "Could not open file." << endl;
        return -1;
    }

    vector<string> lines;
    map<string, set<vector<string>::size_type>> appearLines;

    vector<string>::size_type linenumber = 0;
    for(string s; getline(input, s); ++linenumber){
        istringstream tempProcess(s);
        for(string tempString; tempProcess >> tempString;)
            appearLines[tempString].insert(linenumber);
        lines.push_back(s);
    }

    while(true){
        cout << "What word do you want to query?" << endl;
        string s;
        if(cin >> s && s != "q"){
            if(appearLines.find(s) != appearLines.end()){ //we could omit this if we like, in the case of not existing it still outputs correctly, but it's probably best not to unnecessarily create elements
                cout << s << " appears " << appearLines[s].size() << " times " << endl;
                for(const auto& c : appearLines[s]){
                    cout << "(line " << c+1 << ") " << lines[c] << endl;
                }
            }
            else cout << s << "appears 0 times." << endl;
        }
        else break;
    }


}










