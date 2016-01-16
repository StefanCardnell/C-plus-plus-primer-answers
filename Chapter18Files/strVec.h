#ifndef STRVEC
#define STRVEC

#include <memory> //allocator type
#include <string>
#include <utility> //pair type
#include <initializer_list>

class strVec{
    friend bool operator==(const strVec&, const strVec&);
    friend bool operator!=(const strVec&, const strVec&);
    friend bool operator>(const strVec&, const strVec&);
    friend bool operator<(const strVec&, const strVec&);
    friend bool operator<=(const strVec&, const strVec&);
    friend bool operator>=(const strVec&, const strVec&);

public:

    /*Default and move constructors we can specify noexcept since they just copy pointers (move-assignment also does free()
    but this throws no exceptions. The copy operations however copy strings, and allocate on to the heap, and may throw.
    The destructor has the implicit defined noexcept specification. We know free() will not throw, so the only way it can
    throw is from destructing the allocator and pointers. The implicit noexcept will verify whether this process takes care
    of specificy whether the destructor throws or not */

    strVec() noexcept : firstElem(nullptr), firstFree(nullptr), finalElem(nullptr) { }
    strVec(std::initializer_list<std::string>);

    strVec(const strVec&);
    strVec& operator=(const strVec&);
    strVec(strVec&&) noexcept;
    strVec& operator=(strVec&&) noexcept;
    ~strVec() { free(); }

    strVec& operator=(const std::initializer_list<std::string>&);
    std::string& operator[](size_t n) { return firstElem[n];}
    const std::string& operator[](size_t n) const { return firstElem[n];}

    std::string* begin() const { return firstElem;}
    std::string* end() const {return firstFree; }
    size_t size() const {return firstFree-firstElem;}
    size_t capacity() const {return finalElem - firstElem; }
    void reserve(size_t n) { if(n > capacity()) reallocate(n); }
    void resize(size_t, const std::string& = std::string());
    void push_back(const std::string&);
    template <typename... Args> void emplace_back(Args&&...);
private:
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void check_n_alloc();
    void reallocate(size_t);
    void free();
    std::allocator<std::string> alloc;
    std::string* firstElem;
    std::string* firstFree;
    std::string* finalElem;
};

bool operator==(const strVec&, const strVec&);
bool operator!=(const strVec&, const strVec&);
bool operator>(const strVec&, const strVec&);
bool operator<(const strVec&, const strVec&);
bool operator<=(const strVec&, const strVec&);
bool operator>=(const strVec&, const strVec&);

template <typename... Args> inline void strVec::emplace_back(Args&&... args){

    check_n_alloc();
    alloc.construct(firstFree++, std::forward<Args>(args)...);

}

#endif // STRVEC
