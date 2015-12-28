#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

using namespace std;



int main(){

    int sum = 0, val = 1;

    while (val <= 10) sum += val, ++val;

    cout << "Sum of 1 to 10 inclusive is " << sum << endl;

    return 0;
}


