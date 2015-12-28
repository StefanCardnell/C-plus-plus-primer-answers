#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

using namespace std;



int main(){

    cout << "Void: " << sizeof(void) << " bytes (" << 8*sizeof(void) << " bits)" << endl;
    cout << "Bool: " << sizeof(bool) << " bytes (" << 8*sizeof(bool) << " bits)" << endl;
    cout << "Char: " << sizeof(char) << " bytes (" << 8*sizeof(char) << " bits)" << endl;
    cout << "Wchar_t: " << sizeof(wchar_t) << " bytes (" << 8*sizeof(wchar_t) << " bits)" << endl;
    cout << "Char16_t: " << sizeof(char16_t) << " bytes (" << 8*sizeof(char16_t) << " bits)" << endl;
    cout << "Char32_t: " << sizeof(char32_t) << " bytes (" << 8*sizeof(char32_t) << " bits)" << endl;
    cout << "Short: " << sizeof(short) << " bytes (" << 8*sizeof(short) << " bits)" << endl;;
    cout << "Int: " << sizeof(int) << " bytes (" << 8*sizeof(int) << " bits)" << endl;
    cout << "Long: " << sizeof(long) << " bytes (" << 8*sizeof(long) << " bits)" << endl;
    cout << "Long Long: " << sizeof(long long) << " bytes (" << 8*sizeof(long long) << " bits)" << endl;
    cout << "Float: " << sizeof(float) << " bytes (" << 8*sizeof(float) << " bits)" << endl;
    cout << "Double: " << sizeof(double) << " bytes (" << 8*sizeof(double) << " bits)" << endl;
    cout << "Long Double: " << sizeof(long double) << " bytes (" << 8*sizeof(long double) << " bits)" << endl;



}



