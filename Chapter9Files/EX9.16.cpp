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
#include <array>
#include <list>


//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;


bool compare(vector<int> vec1, list<int> list1){

    if(vec1.size() != list1.size())
        return false;
    else{

        vector<int>::size_type subscript = 0;
        for(auto c : list1){
            if( c != vec1[subscript] ) return false;
            ++subscript;
        }

    }

    return true;

}


int main(){

    vector<int> vec1 = {1,2,3,4};
    list<int> list1 = {1,2,3,4};



    cout << (compare(vec1, list1) ? "true" : "false") << endl;


    //alternatively

    cout << (vector<int>(list1.begin(), list1.end()) == vec1 ? "true" : "false") << endl;


}










