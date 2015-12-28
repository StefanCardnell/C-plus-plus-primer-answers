#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE



//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)


using namespace std;


constexpr bool isShorter(const char* s1, const char* s2){ //use c_str() member function on strings in order to pass strings
    return strlen(s1) < strlen(s2);
}




int main(){



}



