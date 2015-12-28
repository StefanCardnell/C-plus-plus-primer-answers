#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//PUNCTUATION REMOVER!

int main()
{
    string s;

    getline(cin, s);

    for(auto c : s)
        if(!ispunct(c))
            cout << c;

}
