#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring> //c-style string functions
#include <stdexcept> //for runtime_error exceptions and other

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;

int main(){

    int a, b;

    cout << "Enter two integers: " << endl;

    while(cin >> a >> b){

        try{
            if(b == 0) throw runtime_error("Divisor is 0");
            cout << a/b << endl;
            cout << "Enter two integers: " << endl;

        }catch(runtime_error err){
            cout << err.what() << ", please re-enter the divisor." << endl;
            while(cin >> b){
                try{
                    if(b == 0) throw runtime_error("divisor is 0...again");
                    cout << a/b << endl;
                    cout << "Enter two integers: " << endl;
                    break;
                }catch(runtime_error err2){
                    cout << err2.what() << ", please re-enter the divisor." << endl;
                }
            }
        }
    }

    return 0;

}


