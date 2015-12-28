#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

using namespace std;



int main(){

int a[3] = {0,1,2};

auto x = (a+3) - a;

cout << x;


}



