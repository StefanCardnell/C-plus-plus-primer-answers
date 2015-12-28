#include <iostream>
#include <string>

using namespace std;

struct Sales_Data{
string booknumber;
unsigned unitssold = 0;
double revenue = 0;
};


int main(){

    Sales_Data isbn, current;

    if(cin >> isbn.booknumber >> isbn.unitssold >> isbn.revenue){
        unsigned totalnumber = isbn.unitssold;
        while(cin >> current.booknumber >> current.unitssold >> current.revenue){
            if(current.booknumber == isbn.booknumber){
                    totalnumber += current.unitssold;
            }
            else{
                cout << isbn.booknumber << " " << totalnumber << endl;
                isbn.booknumber = current.booknumber;
                totalnumber = current.unitssold;
            }
        }

        cout << isbn.booknumber << " " << totalnumber << endl;

    }

    return 0;
}
