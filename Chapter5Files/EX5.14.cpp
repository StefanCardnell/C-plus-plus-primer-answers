#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){

    unsigned maxrep = 0, currentcount = 1;
    string maxstring, current, prev = "";

    while(cin >> current){
        if(current == prev) ++currentcount;
        else{
            if(currentcount > maxrep){
                maxrep = currentcount;
                maxstring = prev;
            }
            currentcount = 1;
            prev = current;
        }
    }

    if(currentcount > maxrep){
        maxrep = currentcount;
        maxstring = prev;
    }

    if(maxrep == 1) cout << "No word was repeated." << endl;
    else cout << maxstring << " occurred " << maxrep << " times." << endl;

}


