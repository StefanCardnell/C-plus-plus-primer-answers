#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes



//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;

void swapping(int* p, int* q){

    int temp = *p;
    *p = *q;
    *q = temp;


}

int main(){

    int n = 1, r = 2;

    swapping(&n, &r);

    cout << n << " " << r << endl;

}


