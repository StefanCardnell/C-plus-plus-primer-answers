#include "Bulk_Quote.h"

using namespace std;

Bulk_Quote::Bulk_Quote() {
    cout << "Bulk_Quote::Bulk_Quote()" << endl;
}

Bulk_Quote::Bulk_Quote(const string& b, double p, double q, double d): Disk_Quote(b,p,q,d) {
    cout << "Bulk_Quote::Bulk_Quote(const string&, double, double, double)" << endl;
}

Bulk_Quote::Bulk_Quote(const Bulk_Quote& rhs): Disk_Quote(rhs) {
    cout << "Bulk_Quote::Bulk_Quote(const Bulk_Quote&)" << endl;
}

Bulk_Quote::Bulk_Quote(Bulk_Quote&& rhs) noexcept: Disk_Quote(std::move(rhs)) {
    cout << "Bulk_Quote::Bulk_Quote(Bulk_Quote&&)" << endl;
}

Bulk_Quote& Bulk_Quote::operator=(const Bulk_Quote& rhs) {
    Disk_Quote::operator=(rhs);
    cout << "Bulk_Quote::operator=(const Bulk_Quote&)" << endl;
    return *this;
}

Bulk_Quote& Bulk_Quote::operator=(Bulk_Quote&& rhs) noexcept {
    Disk_Quote::operator=(std::move(rhs));
    cout << "Bulk_Quote::operator=(Bulk_Quote&&)" << endl;
    return *this;
}

Bulk_Quote::~Bulk_Quote() {
    cout << "Bulk_Quote::~Bulk_Quote()" << endl;
}

Bulk_Quote* Bulk_Quote::clone() const & {  return new Bulk_Quote(*this);  }

Bulk_Quote* Bulk_Quote::clone() && {  return new Bulk_Quote(std::move(*this));  }
