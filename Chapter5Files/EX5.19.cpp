#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){

    string rsp;

    do{
        cout << "Please enter two strings: " << endl;
        string first, second;
        cin >> first >> second;
        cout << (first.size() <= second.size() ? second : first) << " is larger than the other. " << endl;

        cout << "Go again? " << endl;
        cin >> rsp;
    }while(!rsp.empty() && (rsp[0] == 'y' || rsp[0] == 'Y'));


    return 0;

}


