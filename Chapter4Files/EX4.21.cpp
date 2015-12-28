#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

using namespace std;



int main(){

    vector<int> v1{1,2,3,4,5,6,7};

    for(auto &c : v1){
        c *= c%2==0 ? 1 : 2;
        cout << c << endl;
    }
}



