#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{

    vector<string> text;

    string temp;

    while(getline(cin, temp))
        text.push_back(temp);

    bool x = true;

    for (auto it = text.begin(); it != text.end(); ++it){
        if(it->empty()) x = false;
        if(x) for(auto j = it->begin(); j != it->end(); j++) *j = toupper(*j);
        cout << *it << endl;
    }


}


