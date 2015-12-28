#include <iostream>
#include "EX6.8.h"

using namespace std;

int f = 2;


void fact(){

    cout << "Please enter the number you want the factorial of" << endl;

    int x;

    cin >> x;

    int temp = 1;

    while(x>1)
        temp *= x--;

    cout << "The factorial of " << x << " is " << temp << "." << endl;


}

int abs(int x){

    if(x<0)
        return -x;
    else return x;


}
