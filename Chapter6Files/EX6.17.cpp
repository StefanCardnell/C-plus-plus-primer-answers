#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes



//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


bool anycapitals(const string& s){

    for(auto c : s)
        if(isupper(c)) return true;

    return false;


}

void lowercase(string& s){

    for(auto& c : s)
        c = tolower(c);

}


int main(){

    string s = "Hello Matey";

    cout << anycapitals(s) << endl;

    lowercase(s);

    cout << s << endl;





}


