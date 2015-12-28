#include <iostream>
#include <string>
#include "Sales_Data.h"

using namespace std;

int main(){

    Sales_Data isbn, current, sum;

    if(cin >> isbn.booknumber >> isbn.unitssold >> isbn.revenue){
        sum.booknumber = isbn.booknumber;
        sum.unitssold = isbn.unitssold;
        sum.revenue = sum.unitssold*isbn.revenue;
        while(cin >> current.booknumber >> current.unitssold >> current.revenue){
            if(current.booknumber == isbn.booknumber){
                    sum.unitssold += current.unitssold;
                    sum.revenue += current.unitssold*current.revenue;
            }
            else{
                cout << isbn.booknumber << " " << sum.unitssold << " " << sum.revenue << " ";
                if(sum.unitssold != 0) cout << sum.revenue/sum.unitssold << endl;
                else cout << "(no sales)" << endl;
                isbn.booknumber = current.booknumber;
                sum.unitssold = current.unitssold;
                sum.revenue = sum.unitssold*current.revenue;
            }
        }

        cout << isbn.booknumber << " " << sum.unitssold << " " << sum.revenue << " ";
                if(sum.unitssold != 0) cout << sum.revenue/sum.unitssold << endl;
                else cout << "(no sales)" << endl;

    }
    else {
    cerr << "No data?!" << endl;
    return -1;
    }

    return 0;
}
