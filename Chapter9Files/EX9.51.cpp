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

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support (Mingw-w64 was installed to allow c++11 extra features)

using namespace std;

string tolowerstring(string s){
        for(auto& c : s)
            c = tolower(c);
        return s;
}

string number = "0123456789";

class theWall{

public:
    theWall() = default;
    theWall(string date);
    unsigned year = 0, month = 0, day = 0;

};

theWall::theWall(string date){

    string::size_type place = 0;
    place = date.find_first_of(" /,.");
    if(date.substr(0, place).find_first_of(number) != string::npos)
        month = stoi(date.substr(0, place));
    else if(tolowerstring(date.substr(0, 3)) == "jan") month = 1;
    else if(tolowerstring(date.substr(0, 3)) == "feb") month = 2;
    else if(tolowerstring(date.substr(0, 3)) == "mar") month = 3;
    else if(tolowerstring(date.substr(0, 3)) == "apr") month = 4;
    else if(tolowerstring(date.substr(0, 3)) == "may") month = 5;
    else if(tolowerstring(date.substr(0, 3)) == "jun") month = 6;
    else if(tolowerstring(date.substr(0, 3)) == "jul") month = 7;
    else if(tolowerstring(date.substr(0, 3)) == "aug") month = 8;
    else if(tolowerstring(date.substr(0, 3)) == "sep") month = 9;
    else if(tolowerstring(date.substr(0, 3)) == "oct") month = 10;
    else if(tolowerstring(date.substr(0, 3)) == "nov") month = 11;
    else if(tolowerstring(date.substr(0, 3)) == "dec") month = 12;

    place = date.find_first_of(number, place);

    date = date.substr(place);

    day = stoi(date, &place);

    place = date.find_first_of(number, place);

    year = stoi(date.substr(place));

}

int main(){

    /*ASSUMES FORMAT IS MONTH*DAY*YEAR where * can be anything that separates the values (e.g. " ", ".", "/")
     and month may be as a word or number, day contains at least a number and so does year*/
    /*e.g. "April 2nd 1923" works fine, so does "10 14 1923" */

    theWall x("10 14 1923");

    cout << x.month << " " << x.day << " " << x.year;


}










