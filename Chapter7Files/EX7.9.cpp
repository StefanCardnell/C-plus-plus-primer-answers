//#define NDEBUG
#include <iostream>
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro

//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;



struct Person{
    friend ostream& print(ostream& os, const Person& data);
    friend istream& read(istream& is, Person& data);
    Person() = default;
    Person(string s, string v): name(s), address(v) { }
    explicit Person(istream& is);
    private:
        string name;
        string address;
    public:
        string getname() const { return name;}
        string getaddress() const { return address;}

};

Person::Person(istream& is){
    read(is, *this);
}

ostream& print(ostream& os, const Person& data){
    os << data.name << " " << data.address;
    return os;
}

istream& read(istream& is, Person& data){
    is >> data.name >> data.address;
    return is;
}

int main(){

    Person a(cin);
    print(cout, a);


}






