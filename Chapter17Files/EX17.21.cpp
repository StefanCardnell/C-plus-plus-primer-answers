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
#include <string>
#include <regex>


using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const smatch& m){
    if(m[1].matched)
        return (m[3].matched) && (!m[4].matched || m[4].str() == " ");
    else
        return (!m[3].matched) && (m[4].str() == m[6].str());

}

int main(){

    vector<PersonInfo> people = {{"dave", {"999-999-9993", "(090)9999294"}},
                                 {"bill", {"(090)-923-2932", "9283922222"}},
                                 {"charlie", {"(842)023-2102", "039.029.3023"}}};

    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";

    regex r(pattern);

    for (const auto &entry : people) { // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones) { // for each number
            smatch s;
            regex_match(nums, s, r);
            if (s.empty() || !valid(s)) badNums << " " << nums; //no match or invalid match
            else formatted << " " << nums;
        }
        if (badNums.str().empty())  cout << entry.name << " " << formatted.str() << endl;
        else cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
    }


}














