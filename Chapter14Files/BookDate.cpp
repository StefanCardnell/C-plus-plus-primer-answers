#include "BookDate.h"

using namespace std;

Date::Date(std::istream& is){
    is >> *this;
}

ostream& operator<<(ostream& os, const Date& rhs){
    os << rhs.day << "/" << rhs.month << "/" << rhs.year;
    return os;
}

istream& operator>>(istream& is, Date& rhs){

    is >> rhs.day >> rhs.month >> rhs.year;
    if(!is) //at some point this needs to check day and month are valid (e.g. no month value of 100 or -1, or only 28 days in February)
        rhs = Date();
    return is;

}

bool operator==(const Date& lhs, const Date& rhs){
    return (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year);
}

bool operator!=(const Date& lhs, const Date& rhs){
    return !(lhs == rhs);
}

bool operator<(const Date& lhs, const Date& rhs){ //a<b if a is a date occurring before b
    if(lhs.year < rhs.year)
        return true;
    else if(lhs.year == rhs.year){
        if(lhs.month < rhs.month)
            return true;
        else if(lhs.month == rhs.month){
            if(lhs.day < rhs.day)
                return true;
        }
    }
    return false;
}

bool operator>(const Date& lhs, const Date& rhs){
    return (rhs < lhs);
}

bool operator<=(const Date& lhs, const Date& rhs){
    return !(rhs < lhs);
}

bool operator>=(const Date& lhs, const Date& rhs){
    return !(lhs < rhs);
}














Book::Book(std::istream& is){
    is >> *this;
}

ostream& operator<<(ostream& os, const Book& rhs){
    os << rhs.author << ": " << rhs.title << " (" << rhs.release << ")";
    return os;
}

istream& operator>>(istream& is, Book& rhs){
    getline(is, rhs.title); //minimal input formatting, we need cin.ignore(256, '\n') to avoid input errors but leave this to the user
    getline(is, rhs.author);
    is >> rhs.release;
    if(!is)
        rhs = Book();
    return is;
}

bool operator==(const Book& lhs, const Book& rhs){
    return (lhs.title == rhs.title && lhs.author == rhs.author && lhs.release == rhs.release);
}
bool operator!=(const Book& lhs, const Book& rhs){
    return !(lhs == rhs);
}


