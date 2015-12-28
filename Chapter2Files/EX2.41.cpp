#include <iostream>
#include <cstdlib>

using namespace std;

struct Sales_Data{

string booknumber;
unsigned unitssold = 0;
double revenue = 0;
};

Sales_Data book1, book2;

int main(){

    double price;
    cin >> book1.booknumber >> book1.unitssold >> price;
    book1.revenue = price*book1.unitssold;

    cin >> book2.booknumber >> book2.unitssold >> price;
    book2.revenue = price*book2.unitssold;

    if(book1.booknumber == book2.booknumber){
        unsigned totalcount = book1.unitssold + book2.unitssold;
        double totalrevenue = book1.revenue + book2.revenue;
        cout << book1.booknumber << " " << totalcount << " " << totalrevenue << " ";
        if(totalcount != 0){
            cout << totalrevenue/totalcount << endl;
        }
        else
            cout << "(no sales)" << endl;
        return 0;
    }
    else{
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }

}
