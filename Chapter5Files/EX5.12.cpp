#include <iostream>
#include <string>
#include <vector>
#include <cstddef> //use of size_t and ptrdiff_t
#include <cstring>

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


int main(){

    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             tabCnt = 0, spaceCnt = 0, lineCnt = 0, ffCnt= 0,
             fiCnt = 0, flCnt = 0;

    char c;

    while (cin >> noskipws >> c) {

        bool x = false;

            switch (c) {
                case 'a':
                case 'A':
                    ++aCnt;
                    break;
                case 'e':
                case 'E':
                    ++eCnt;
                    break;
                case 'i':
                    if(x) ++fiCnt;
                case 'I':
                    ++iCnt;
                    break;
                case 'o':
                case 'O':
                    ++oCnt;
                    break;
                case 'u':
                case 'U':
                    ++uCnt;
                    break;
                case '\t':
                    ++tabCnt;
                    break;
                case ' ':
                    ++spaceCnt;
                    break;
                case '\n':
                    ++lineCnt;
                    break;
                case 'f':
                    if(x) ++ffCnt;
                    break;
                case 'l':
                    if(x) ++flCnt;
                    break;
            }

            c == 'f' ? x = true : x = false;


    }




    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of tabs: \t" << tabCnt << '\n'
         << "Number of newlines: \t" << lineCnt << '\n'
         << "Number of spaces: \t" << spaceCnt << '\n'
         << "Number of ff: \t" << ffCnt << '\n'
         << "Number of fi: \t" << fiCnt << '\n'
         << "Number of fl: \t" << flCnt << endl;




}


