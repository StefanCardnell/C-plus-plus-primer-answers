#include <iostream>
#include <string>

using namespace std;

struct Sales_Data{
string booknumber;
unsigned unitssold = 0;
double revenue = 0;
};


int main(){

    Sales_Data isbn, current, sum;

    if(cin >> isbn.booknumber){
        cin >> sum.unitssold >> sum.revenue;
        sum.revenue = sum.unitssold*sum.revenue;
        while(cin >> current.booknumber >> current.unitssold >> current.revenue){
            if(current.booknumber == isbn.booknumber){
                    sum.unitssold += current.unitssold;
                    sum.revenue += current.unitssold*current.revenue;
            }
            else{
                cerr << "ISBN values not all the same. Try again." << endl;
                return -1;
            }
        }
        cout << isbn.booknumber << " " << sum.unitssold << " " << sum.revenue << " ";
        if(sum.unitssold !=0){
        cout << sum.revenue/sum.unitssold << endl;
        }
        else cout << "(no sales)" << endl;

    }

    return 0;
}
