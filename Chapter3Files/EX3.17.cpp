#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{

    vector<string> holder;

    string temp;

    while(cin >> temp) holder.push_back(temp);

    for(auto &c : holder)
        for(auto &d : c)
            d = toupper(d);


    int i = 0;
    int j = 0;

    for(auto c : holder){
        cout << c << " ";
        i++;
        if(i/8 != j){
            cout << endl;
            j = i/8;
        }

    }

}


