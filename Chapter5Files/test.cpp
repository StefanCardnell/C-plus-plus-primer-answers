#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring> //c-style string functions
#include <stdexcept> //for plain/runtime/logic exceptions

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int fact(int val, double){
    return 2;
}

int fact2(int val, double){
    return 2;
}


int main(){

    cout << &fact << "" << &fact2 << endl;


}


