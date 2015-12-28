#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type



//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;

void print(vector<int> v, vector<int>::size_type b){
    cout << v[b-1] << endl;
    if(b>1)
    print(v, b-1);

}

int main(){

    vector<int> v = {1,2,3,4,5,6,7,8};

    print(v,v.size());

    return 0;

}



