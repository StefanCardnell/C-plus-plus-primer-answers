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

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
return (ctr > 1) ? word + ending : word;
}

int main(){

    cout << make_plural(1, "success", "es") << " " << make_plural(1, "failure") << endl;

    cout << make_plural(2, "success", "es") << " " << make_plural(2, "failure");



}



