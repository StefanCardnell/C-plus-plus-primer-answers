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
//#include <typeinfo> //bad_cast exception

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

#include <iostream>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <map>
#include <vector>

/*So there's only two ways I could see this being possible

    1. Create iPhone level of autocorrect to change the output of type_info::name to remove numbers, underscores, identify the proper
    name, etc. in order to produce the correct name. This is laborious and absurd.
    2. If I cannot automatically generate the correct names, then I must keep a list to match each output of typeid to its proper name which
    indicates the use of a map (match each typeid key with a string). Unfortunately I'm not sure how to do this for every single array
    size and it also requires me to know the types beforehand. So the following is the "best I can do", the only way to put typeinfo objects
    in to a map is to use typeindex instead (see cppreference), since typeinfo is not default/copy constructible and cannot be used as a key.

*/



class Base{
public:
    virtual ~Base() {}
};

class Derived: public Base { };

const std::string& proper_name(const std::type_info& t){

    static const std::string noResult = "Type could not be identified.";

    static const std::map<std::type_index, std::string> names = {
        {typeid(int), "int"}, {typeid(double), "double"}, {typeid(float), "float"}, {typeid(char), "char"},
        {typeid(Base), "Base"}, {typeid(Derived), "Derived"}, {typeid(std::string), "String"},
        {typeid(int[10]), "Ten int Array"}, {typeid(Base*), "Base Pointer"}
    };


    auto it = names.find(t);

    if(it != names.end()){
        return (*it).second;
    }
    else return noResult;


}

int main(){

    int arr[10];
    Derived d;
    Base *p = &d;


    std::cout << proper_name(typeid(42)) << ", "
              << proper_name(typeid(arr)) << ", "
              << proper_name(typeid(std::string)) << ", "
              << proper_name(typeid(p)) << ", "
              << proper_name(typeid(*p)) << std::endl
              << proper_name(typeid(unsigned)) << std::endl;





}





