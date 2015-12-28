#ifndef HASPTRVALUE
#define HASPTRVALUE

#include <string>
#include <iostream>

class HasPtrValue {
    friend void swap(HasPtrValue&, HasPtrValue&);
public:
    HasPtrValue(const HasPtrValue& h): ps(new std::string(*h.ps)), i(h.i) {}
    HasPtrValue(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtrValue& operator=(const HasPtrValue&);
    HasPtrValue& operator=(HasPtrValue&&) noexcept;
    ~HasPtrValue() { delete ps; }
    bool operator<(const HasPtrValue& rhs) const { return *ps < *rhs.ps; }
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtrValue& lhs, HasPtrValue& rhs){
    std::cout << "Executing swap." << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


#endif // HasPtrValue
