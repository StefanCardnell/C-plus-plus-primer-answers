#ifndef sTRING
#define sTRING

#include <memory> //allocator type
#include <utility> //pair type
#include <iostream>

class String{
public:
    String(): String("") { std::cout << "Default" << std::endl;}
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String() { free(); }

    char* begin() const { return firstElem;}
    char* end() const {return firstFree; }
    size_t size() const {return firstFree-firstElem;}
    size_t capacity() const {return finalElem - firstElem; }
    void reserve(size_t n) { if(n > capacity()) reallocate(n); }
    void resize(size_t, const char& = char());
    void push_back(const char&);
private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void check_n_alloc();
    void reallocate(size_t);
    void free();
    std::allocator<char> alloc;
    char* firstElem;
    char* firstFree;
    char* finalElem;

};


#endif // String
