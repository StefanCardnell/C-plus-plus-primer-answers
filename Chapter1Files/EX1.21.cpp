#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(){

    while(true){
        Sales_item book1, book2;
        cin >> book1 >> book2;

        if(compareIsbn(book1, book2)) cout << book1 + book2 << endl;
        else cout << "ISBN values not the same" << endl;

        cout << "Go again? (0:NO or 1:YES)" << endl;
        int answer;
        cin >> answer;
        if(answer==0) break;


    }
    return 0;
}
