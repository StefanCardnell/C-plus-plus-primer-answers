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
#include <sstream>
#include <iomanip>

using namespace std;

int main(){

    cout << boolalpha << "Boolalpha: " << bool(true) << endl;
    cout << noboolalpha << "NoBoolalpha: " << bool(true) << endl;

    cout << dec << "\nDecimal 10: " << 10 << endl;
    cout << oct << "Oct 10: " << 10 << endl;
    cout << hex << "Hex 10: " << 10 << endl;


    cout << showbase;
    cout << dec << "\nDecimal 10 w/ base shown: " << 10 << endl;
    cout << oct << "Oct 10 w/ base shown: " << 10 << endl;
    cout << hex << "Hex 10 w/ base shown: " << 10 << endl;


    cout << uppercase;
    cout << dec << "\nDecimal 10 w/ base shown w/ uppercase: " << 10 << endl;
    cout << oct << "Oct 10 w/ base shown w/ uppercase: " << 10 << endl;
    cout << hex << "Hex 10 w/ base shown w/ uppercase: " << 10 << endl;
    cout << noshowbase << nouppercase << dec;

    cout << setbase(8) << "\n37 output in using setbase(8): " << 9 << endl;
    cout << setbase(10);


    double d = 1234.5678;

    cout << "\nPrecision: " << cout.precision() << "   Output of 1234.5678: " << d << endl;
    cout << setprecision(10);
    cout << "Precision: " << cout.precision() << "   Output of 1234.5678: " << d << endl;
    cout << setprecision(2);
    cout << "Precision: " << cout.precision() << "   Output of 1234.5678: " << d << endl;
    cout << setprecision(6);

    cout << showpoint;
    cout << "\nshowpoint Output of 10. w/ precision 6: " << 10. << endl;
    cout << noshowpoint;
    cout << "noshowpoint Output of 10. w/ precision 6: " << 10. << endl;

    cout << showpos;
    cout << "\nshowpos on 10: " << 10 << endl;
    cout << "showpos on 10.23: " << 10.23 << endl;
    cout << noshowpos;
    cout << "noshowpos on 10: " << 10 << endl;
    cout << "noshowpos on 10.23: " << 10.23 << endl;


    cout << "\nDefault output of 1234.5678: " << d << endl;
    cout << scientific << "Scientific output of 1234.5678: " << d << endl;
    cout << setprecision(8) << "Scientific output of 1234.5678 w/ Precision 8: " << d << endl;
    cout << setprecision(6) << fixed << "Fixed output of 1234.5678: " << d << endl;
    cout << setprecision(8) << "Fixed output of 1234.5678 w/ Precision 8: " << d << endl;
    cout << defaultfloat << setprecision(6) << "Back to default: " << d << endl;

    cout << "\nOutput -3.2 and then 1.62341: " << endl;
    cout << -3.2 << 1.62341 << endl;
    cout << "Output -3.2 and then 1.62341 with setw(10): " << endl;
    cout << setw(10) << -3.2 << 1.62341 << endl;
    cout << "Output -3.2 and then 1.62341 with setw(10) and left justification: " << endl;
    cout << setw(10) << left << -3.2 << 1.62341 << endl;
    cout << "Output -3.2 and then 1.62341 with setw(10) and internal justification: " << endl;
    cout << setw(10) << internal << -3.2 << 1.62341 << endl;
    cout << "Output 3.2 and then 1.62341 with setw(10) and internal justification and showpos: " << endl;
    cout << setw(10) << showpos << internal << 3.2 << 1.62341 << noshowpos << endl;
    cout << "Output -3.2 and then 1.62341 with setw(10) and internal justification and setfill('X'): " << endl;
    cout << setw(10) << setfill('X') << internal << -3.2 << 1.62341 << endl;

    cout << left << setfill(' ');

    cout << "\nAfter this line, endl and then 'a': " << endl;
    cout << endl << 'a';
    cout << "\nAfter this line, ends and then 'a': " << endl;
    cout << ends << 'a';
    cout << "\nAfter this line, flush and then 'a': " << endl;
    cout << flush << 'a' << endl;

    cout << "\nskipws input with input \"a b  c\\nd\":" << endl;

    istringstream inputnoskip("a b  c\nd");

    for(char c; inputnoskip >> c;)
        cout << c;

    cout << "\nnoskipws input with input \"a b  c\\nd\":" << endl;

    istringstream inputskip("a b  c\nd");

    inputskip >> noskipws;

    for(char c; inputskip >> c;)
        cout << c;


}















