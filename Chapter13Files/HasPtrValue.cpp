#include "HasPtrValue.h"
#include <iostream>

using namespace std;

HasPtrValue& HasPtrValue::operator=(const HasPtrValue& rhs){
    auto newStr = new std::string(*rhs.ps);
    delete ps;
    ps = newStr;
    i = rhs.i;
    return *this;
}

HasPtrValue& HasPtrValue::operator=(HasPtrValue&& rhs) noexcept {
    if(this != &rhs){
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}



