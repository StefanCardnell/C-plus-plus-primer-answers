#include <iostream>
#include <string>

using namespace std;


int main()
{
    string line1, line2;

    while(cin >> line1 >> line2){
        if(line1 == line2){
            cout << "The strings are equal!" << endl;
        }
        else
            if(line1 > line2){
                cout << line1 << " is bigger." << endl;
            }
            else{
                cout << line2 << " is bigger." << endl;
        }
    }
}
