//#define NDEBUG
//#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
//#include <string>
//#include <vector>
//#include <cstring> //c-style string functions
//#include <cstddef> //for size_t type and ptr_diff type
//#include <cctype> //for chararacter related functions
//#include <stdexcept> //Plain/Runtime/Logic exception classes
//#include <initializer_list> //for initializer_list type
//#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
//#include <cassert> //assert preprocessor macro
//#include <array>
//#include <list>
//#include <deque>
//#include <forward_list>
//#include <stack> //sequential container adaptor
//#include <queue> //sequential container adaptor, includes priority_queue
//#include <algorithm>
//#include <numeric> //more container algorithms
//#include <functional> //for bind library function (and ref/cref), and library defined function objects
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
//#include <memory> //for dynamic memory smart pointers
//#include <new> //nothrow and bad_alloc types, and allocator class
//#include <type_traits> //type transformation templates
//#include <tuple> //tuple class
//#include <bitset> //bitset class
//#include <regex> //regex library
//#include <random> //random-number engines and random-number distribution classes
//#include <ctime> //time function which is good in use with random generators

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*unfortunately errors with mingw/Windows make it hard to use seek/tell with ftstreams, see:
http://stackoverflow.com/questions/34362325/fstream-and-seekg-not-operating-as-intended
http://stackoverflow.com/questions/27055771/using-seekg-in-text-mode

to resolve this it must be opened in binary so that \r\n is not converted to just \n which
is the root of the issue. */

//this program assumes that each file ends with a newline.

int main(){

    fstream inOut("EX17.39file.txt", fstream::ate | fstream::out | fstream::in | fstream::binary);

    if(!inOut){
        cout << "Failed to open file. Exiting." << endl;
        return EXIT_FAILURE;
    }

    auto end_mark = inOut.tellp();
    inOut.seekg(0, fstream::beg);

    size_t cnt = 0;

    for(string line; (inOut.tellg() != end_mark) && getline(inOut, line);){

        auto read_mark = inOut.tellg();
        inOut.seekp(0, fstream::end);

        cnt += line.size() + 1; //lines in binary mode end in \r\n, since the \n gets discarded the lines end in \r.
        inOut << cnt;

        if(read_mark != end_mark)
            inOut << " ";
        inOut.seekg(read_mark);

    }

    inOut.seekp(0, fstream::end);
    inOut << "\r\n"; //opening in text mode normally converts any "\n" output to "\r\n", since we are in binary mode we have to add "\r" ourselves
    inOut.close();


}
