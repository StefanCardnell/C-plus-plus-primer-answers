#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(){

    Sales_item isbn, current, sum;
    if(cin >> isbn){
        sum = isbn;
        while(cin >> current){
            if(compareIsbn(isbn, current)) sum+=current;
            else{
                cout << "ISBN values not all the same. Try again." << endl;
                return 0;
            }
        }
        cout << sum << endl;

    }

    return 0;
}


