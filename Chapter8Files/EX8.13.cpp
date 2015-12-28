//#define NDEBUG
#include <iostream>
#include <fstream>
#include <sstream> //stringstream
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};




int main(){
    string line, word;
    vector<PersonInfo> people;

    ifstream input("hello.txt");

    if(!input){
        cerr << "Failed to open hello.txt" << endl;
        return -1;
    }

    while(getline(input, line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people){
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            cout << entry.name << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s)" << badNums.str() << endl;
    }

}










