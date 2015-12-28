#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring> //c-style string functions
#include <stdexcept> //for plain/runtime/logic exceptions

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int absolute(int x){
    return x < 0 ? -x : x;
}


int main(){

    cout << absolute(-6132);

}


