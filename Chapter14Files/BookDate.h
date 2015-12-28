#ifndef BOOKDATE
#define BOOKDATE

#include <iostream>
#include <string>
#include <initializer_list>

class Date{
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);
    friend bool operator<(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator<=(const Date&, const Date&);
    friend bool operator>=(const Date&, const Date&);
public:
    Date(): Date(1,1,1970) { }
    Date(std::istream& is);
    Date(unsigned d, unsigned m, unsigned y): day(d), month(m), year(y) { }
    explicit operator bool() const { return (*this != Date());}
private:
    unsigned day, month, year;
};

std::ostream& operator<<(std::ostream&, const Date&);
std::istream& operator>>(std::istream&, Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);

class Book{
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
public:
    Book(): Book("Unnamedbook", "Unnamedauthor", Date()) { }
    Book(std::istream& is);
    Book(std::string t, std::string a, Date r): title(t), author(a), release(r) { }
    explicit operator bool() const { return (*this != Book());}
private:
    std::string title, author;
    Date release;
};

std::ostream& operator<<(std::ostream&, const Book&);
std::istream& operator>>(std::istream&, Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);


#endif // BOOKDATE



