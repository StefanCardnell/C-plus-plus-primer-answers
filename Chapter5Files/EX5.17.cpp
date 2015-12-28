#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){

    vector<int> v2 = {1,2,3,4,5}, v1 = {1,2,3,4,5,6,7,8,9};

    bool x = true;

    for(decltype(v1.size()) i = 0; i < v1.size() && i < v2.size(); ++i)
        if(v1[i] != v2[i]){
            x = false;
            break;
        }

    cout << x << endl;



}


