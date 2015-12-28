#ifndef DEBUGDELETE
#define DEBUGDELETE

#include <iostream>

class DebugDelete{
public:
    DebugDelete(std::ostream& o = std::cerr): os(o) { }
    template <typename T> void operator()(T* p) const {  os << "DebugDelete operator() called." << std::endl; delete p;}
private:
    std::ostream& os;

};

#endif // DEBUGDELETE
