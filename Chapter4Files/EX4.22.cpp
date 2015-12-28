#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

using namespace std;



int main(){

    string finalgrade;
    int grade = 76;

    //finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (60 <= grade && grade <= 75) ? "low pass" : "pass";

    /*if(grade > 90) finalgrade = "high pass";
    else if(60 <= grade && grade <= 75) finalgrade = "low pass";
    else if(grade < 60) finalgrade = "fail";
    else finalgrade = "pass";

    cout << finalgrade;*/



    string y = "yes";

    bool x = bool(y);
}



