#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){


    vector<string> v = {"F", "D", "C", "B", "A", "A++"};

    int grade;
    string lettergrade;

    while(cin >> grade){
        if(grade < 60) lettergrade = v[0];
        else{
            lettergrade = v[(grade-50)/10];
            if(grade != 100)
                if(grade%10 > 7) lettergrade += "+";
                else if(grade%10 < 3) lettergrade += "-";
        }
        cout << lettergrade << endl;
    }



}


