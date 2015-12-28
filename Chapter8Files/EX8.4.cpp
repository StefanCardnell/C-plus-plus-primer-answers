//#define NDEBUG
#include <iostream>
#include <fstream>
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

void readinto(string s, vector<string>& contents){
    ifstream in(s);

    if(in){
        string temp;
        while(getline(in, temp))
            contents.push_back(temp);
    }
    else
        cerr << "Couldn't open huh.txt" << endl;

    in.close();

}


int main(){

    vector<string> contents;

    readinto("huh.txt", contents);


    for(auto c : contents)
        cout << c << endl;


}










