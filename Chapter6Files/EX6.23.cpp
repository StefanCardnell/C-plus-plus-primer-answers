#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes



//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


void print(const int *p){

    if(*p) cout << *p << endl;

}

void print(const int* beg, const int* end){

    for(auto i = beg; i != end; ++i)
        cout << *i << endl;

}

void print(const int* p, size_t sizearray){

    for(decltype(sizearray) i = 0; i != sizearray; ++i)
        cout << p[i] << endl;
}

void print(int (&p)[2]){

    for(auto c: p)
        cout << c << endl;

}


int main(){

    int i = 0, j[2] = {0,1};

    print(&i);

    print(begin(j), end(j));

    print(j, end(j)-begin(j));

    print(j);


}


