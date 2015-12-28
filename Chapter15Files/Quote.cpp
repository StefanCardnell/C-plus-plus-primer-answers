#include "Quote.h"

using namespace std;

Quote::Quote() {
    cout << "Quote::Quote()" << endl;
}

Quote::Quote(const string& s, double sales_price): bookNo(s), price(sales_price) {
    cout << "Quote::Quote(const string&, double)" << endl;
}

Quote::Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price) {
    cout << "Quote::Quote(const Quote&)" << endl;
}

Quote::Quote(Quote&& rhs) noexcept: bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
    cout << "Quote::Quote(Quote&&)" << endl;
}

Quote& Quote::operator=(const Quote& rhs) {
    cout << "Quote::operator=(const Quote&)" << endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote& Quote::operator=(Quote&& rhs) noexcept {
    cout << "Quote::operator=(Quote&&)" << endl;
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
}

Quote::~Quote() {
    cout << "Quote::~Quote()" << endl;
}

Quote* Quote::clone() const & {  return new Quote(*this);  }

Quote* Quote::clone() && {  return new Quote(std::move(*this));  }
