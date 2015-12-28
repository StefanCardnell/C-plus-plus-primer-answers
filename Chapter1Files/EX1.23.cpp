#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(){

    Sales_item currentisbn, book;

    if(cin >> currentisbn){
        book = currentisbn;
        int cnt = 1;
        while(cin >> book){
            if(book.isbn() == currentisbn.isbn()){
                cnt++;
            }
            else{
                cout << currentisbn.isbn() << ": " << cnt << " times." << endl;
                currentisbn = book;
                cnt = 1;
            }
        }
        cout << currentisbn.isbn() << ": " << cnt << " times." << endl;
    }

    return 0;

}
