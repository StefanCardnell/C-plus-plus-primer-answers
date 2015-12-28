#ifndef HASPTRPOINTER
#define HASPTRPOINTER

#include <string>
#include <iostream>

class HasPtrPointer {
public:
    HasPtrPointer(const HasPtrPointer& h): ps(h.ps), i(h.i), counter(h.counter) { ++*counter; }
    HasPtrPointer(const std::string &s = std::string()): ps(new std::string(s)), i(0), counter(new size_t(1)) { }
    HasPtrPointer& operator=(const HasPtrPointer&);
    ~HasPtrPointer();
private:
    std::string *ps;
    int i;
    size_t *counter;
};


#endif // HasPtrPointer
