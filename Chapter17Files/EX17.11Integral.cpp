//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <cctype> //for chararacter related functions
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms
#include <functional> //for bind library function (and ref/cref), and library defined function objects
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
#include <unordered_map> //for unordered_map and unordered_multimap
#include <unordered_set> //for unordered_set and unordered_multiset
#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class
#include <type_traits> //type transformation templates
#include <tuple> //tuple class
#include <bitset> //bitset class

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
////ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;

//If it had 100 questions, it would be best to use a bitset

//Actually it's always best to use a bitset, why the fuck is this question making me use an integral
//object again? We JUST demonstrated using an integral object was contrived as fuck.

//in this case we count test questions starting from zero

class studentQuiz{
    friend unsigned testScore(const studentQuiz&, unsigned);
public:
    studentQuiz() = default;
    studentQuiz(unsigned i): response(i) { }

    void updateResponse(unsigned quNo, bool value);
private:
    unsigned response = 0; //this is at least 16 bits
};

void studentQuiz::updateResponse(unsigned quNo, bool value){
    if(value)
        response |= (1U << quNo);
    else
        response &= ~(1U << quNo);
}

unsigned testScore(const studentQuiz& i, unsigned Answers){
    unsigned result = 0;
    for(unsigned j = 0; j != 10; ++j){
        unsigned selection = (1U << j);
        if((i.response & selection) == (Answers & selection))
            ++result;
    }
    return result;
}

static const unsigned testAnswers = 1476; //0111000100

int main(){


    studentQuiz a;

    a.updateResponse(0, false);
    a.updateResponse(1, false);
    a.updateResponse(2, true);
    a.updateResponse(3, false);
    a.updateResponse(4, false);
    a.updateResponse(5, false);
    a.updateResponse(6, true);
    a.updateResponse(7, true);
    a.updateResponse(8, true);
    a.updateResponse(9, false);


    cout << testScore(a, testAnswers);



}














