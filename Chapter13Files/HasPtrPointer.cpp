#include "HasPtrPointer.h"

HasPtrPointer& HasPtrPointer::operator=(const HasPtrPointer& rhs){
    ++*rhs.counter;
    if(--*counter == 0){
        delete ps;
        delete counter;
    }
    ps = rhs.ps;
    i = rhs.i;
    counter = rhs.counter;
    return *this;
}

HasPtrPointer::~HasPtrPointer() {
    if(--*counter == 0){
        delete ps;
        delete counter;
    }
}
