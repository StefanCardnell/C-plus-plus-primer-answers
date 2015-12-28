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
#include "Screen.h"


//difference_type (iterators) and ::size_type are for strings/vectors
//ptrdiff_t and size_t are for arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support

using namespace std;


class Date{
public:
    Date(): Date(1,1,1970) { }
    Date(unsigned d, unsigned m, unsigned y): day(d), month(m), year(y) { }
    Date(istream& is): Date() { is >> day >> month >> year;}
    void readout(ostream&) const;
private:
    unsigned day, month, year;
};

class Book{
public:
    Book(): Book("Unnamedbook", "Unnamedauthor", Date()) { }
    Book(istream& is): Book() { getline(is, title); getline(is, author); release = Date(is); }
    Book(string t, string a, Date r): title(t), author(a), release(r) { }
    void readout(ostream&) const;
private:
    string title, author;
    Date release;

};

void Date::readout(ostream& os) const{
    os << day << "/" << month << "/" << year;
}

void Book::readout(ostream& os) const {
    os << "\"" << title << "\" by " << author << ", published: ";
    release.readout(os);
}


int main(){



    const Book testbook("the road", "cormac mccarthy", Date(2,4,2009));

    testbook.readout(cout);



}








