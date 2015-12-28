#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{

    vector<int> ivec;

    int temp;

    while(cin >> temp)
        ivec.push_back(temp);

    for(decltype(ivec.size()) i = 0; i <= ivec.size()-1-i; i++)
        cout << ivec[i] + ivec[ivec.size()-1-i] << endl;


}


