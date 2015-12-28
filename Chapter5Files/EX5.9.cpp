#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){


    char c;
    unsigned vowelCnt = 0;

    while(cin >> c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowelCnt++;
    }

    cout << vowelCnt << endl;

}


