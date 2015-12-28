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
//#include <random> //random-number engines and random-number distribution classes
//#include <ctime> //time function which is good in use with random generators

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <map>
#include <utility>
#include <ctime>

using namespace std;

unsigned randomUns(unsigned minV, unsigned maxV, default_random_engine::result_type seed = 0){

    static map<default_random_engine::result_type, default_random_engine> generators;
    static map<pair<unsigned, unsigned>, uniform_int_distribution<unsigned>> distributions;

    pair<unsigned, unsigned> range(minV, maxV);

    if(generators.find(seed) == generators.end()){
        generators.insert({seed, default_random_engine(seed)});
        generators[seed].discard(1); //the first generated value tends not to change all that much with seed, discard it.
    }

    if(distributions.find(range) == distributions.end())
       distributions.insert({range, uniform_int_distribution<unsigned>(range.first, range.second)});

    return distributions[range](generators[seed]);

}

map<string, vector<string>> transformPhrase(ifstream& phrases){

    map<string, vector<string>> replacements;

    for(string word, phrase; phrases >> word && getline(phrases, phrase); ){
        if(phrase.size() > 1){
            for(string::size_type pos = 0, start = 1; (pos = phrase.find_first_of(';', pos)) != string::npos;){ //each phrase must end with a ; "e.g. brb be right back;back in a jiffy;afk;
                replacements[word].push_back(phrase.substr(start, pos-start));
                start = (++pos);
            }
        }
        else throw runtime_error("No phrase supplied for " + word);
    }

    return replacements;

}

const string& returnTransformed(const string& s, const map<string, vector<string>>& m){ //we can declare map as const since we aren't using subscript

    static time_t t = time(0);

    auto it = m.find(s);
    if(it == m.cend()) return s;
    else return (it->second)[randomUns(0,it->second.size() - 1, t)];

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



    ifstream input("EX17.33input.txt"), phrases("EX17.33phrases.txt");

    if(!input || !phrases){
        cout << "File couldn't be opened" << endl;
        return EXIT_FAILURE;
    }

    fileTransform(phrases, input);


}















