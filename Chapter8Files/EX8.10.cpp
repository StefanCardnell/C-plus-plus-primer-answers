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




int main(){

    vector<string> lines;
    ifstream input("huh.txt");

    if(input){
        string temp;
        while(getline(input, temp))
            lines.push_back(temp);
        input.close();
        for(auto c : lines){
            istringstream lineread(c);
            while(lineread >> temp)
                cout << temp << endl;
        }

    }
    else cerr << "Couldn't open huh.txt" << endl;



}










