#ifndef BOOKDATE
#define BOOKDATE

#include <iostream>
#include <string>

class Date{
public:
    Date(): Date(1,1,1970) { }
    Date(unsigned d, unsigned m, unsigned y): day(d), month(m), year(y) { }
    Date(std::istream& is): Date() { is >> day >> month >> year;}
    void readout(std::ostream&) const;
private:
    unsigned day, month, year;
};

class Book{
public:
    Book(): Book("Unnamedbook", "Unnamedauthor", Date()) { }
    Book(std::istream& is): Book() { getline(is, title); getline(is, author); release = Date(is); }
    Book(std::string t, std::string a, Date r): title(t), author(a), release(r) { }
    void readout(std::ostream&) const;
private:
    std::string title, author;
    Date release;

};

void Date::readout(std::ostream& os) const{
    os << day << "/" << month << "/" << year;
}

void Book::readout(std::ostream& os) const {
    os << "\"" << title << "\" by " << author << ", published: ";
    release.readout(os);
}

#endif // BOOKDATE



