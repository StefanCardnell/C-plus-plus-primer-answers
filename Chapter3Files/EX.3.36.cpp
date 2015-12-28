#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


using namespace std;


int main(){

int ia[10] = {};
int ib[10] = {};

if(end(ia)-begin(ia) != end(ib)-begin(ib)){
    cout << "Arrays are not equal size" << endl;
    return 0;
}

else{
    auto arraysize = end(ia)-begin(ia);
    for(int i = 0; i < arraysize; i++){
        if(*(ia+i) != *(ib+i)){
            cout << "Array elements are not the same" << endl;
            return 0;
        }
    }
}

cout << "Arrays are the same" << endl;



}



