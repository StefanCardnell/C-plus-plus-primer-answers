#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t
#include <cstring>

using namespace std;



int main(){

constexpr size_t row = 3, col = 4;

int ia[row][col] = { // three elements; each element is an array of size 4
{0, 1, 2, 3}, // initializers for the row indexed by 0
{4, 5, 6, 7}, // initializers for the row indexed by 1
{8, 9, 10, 11} // initializers for the row indexed by 2
};

/*typedef int (*int_array)[4];

for(int_array p = ia; p != ia+3; p++){
    for(int *j = *p; j != *p + 4; j++)
        cout << *j << " ";
    cout << endl;
}*/

/*
typedef size_t why;

for(why i = 0; i != 3; i++){
    for(why j = 0; j != 4; j++)
        cout << ia[i][j] << " ";
    cout << endl;
}*/

/*typedef int j, (&k)[4];

for(k row : ia){
    for(j col : row)
        cout << col << " ";
    cout << endl;
}*/


/*for(auto p = ia; p != ia+3; p++){
    for(auto j = *p; j != *p + 4; j++)
        cout << *j << " ";
    cout << endl;
}*/

/*for(auto i = 0; i != 3; i++){
    for(auto j = 0; j != 4; j++)
        cout << ia[i][j] << " ";
    cout << endl;
}*/

for(auto &row : ia){
    for(auto col : row)
        cout << col << " ";
    cout << endl;
}



}



