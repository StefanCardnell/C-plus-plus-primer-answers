//#define NDEBUG
//#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
//#include <string>
//#include <vector>
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
//#include <functional> //for bind library function (and ref/cref), and library defined function objects
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
//#include <memory> //for dynamic memory smart pointers
//#include <new> //nothrow and bad_alloc types, and allocator class
//#include <type_traits> //type transformation templates
//#include <tuple> //tuple class
//#include <bitset> //bitset class
//#include <regex> //regex library

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <set>

using namespace std;

string lowerCase(string s){
    for(auto& c : s)
        c = tolower(c);
    return s;
}

bool caseIndependentCompare(const string& lhs, const string& rhs){
    return lowerCase(lhs) < lowerCase(rhs);
}

int main(){

    ifstream input("EX17.18violations.txt"); //text file containing words which violate the rule

    if(!input){
        cerr << "Could not open violations file. Exiting" << endl;
        return -1;
    }

    cout << "i before e except after c. Search for mispelt violations." << endl;

    set<string, decltype(caseIndependentCompare)*> violations(caseIndependentCompare);

    for(string temp; input >> temp; violations.insert(temp));

    input.close();

    regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);

    cout << "\nPlease enter a sentence: ";

    for(string word; getline(cin, word);){

        ostringstream os;

        for(sregex_iterator it(word.begin(), word.end(), r), end; it != end; ++it)
            if(violations.find(it->str()) == violations.end())
                os << (it->str()) << " ";

        if(os.str().size() != 0)
            cout << "Mispelt violations found: " << os.str() << endl;
        else cout << "No mispelt violations found." << endl;

        cout << "\nPlease enter another word: ";
    }

    //violates: weird, their, heist
    //does not violate: friend, receive, ceiling, science

}














