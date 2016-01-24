#ifndef STRVEC
#define STRVEC

#include <memory> //allocator type
#include <string>
#include <utility> //pair type
#include <initializer_list>

class strVec{
public:
    strVec(): firstElem(nullptr), firstFree(nullptr), finalElem(nullptr) { }
    strVec(const strVec&);
    strVec(std::initializer_list<std::string>);
    strVec& operator=(const strVec&);
    strVec(strVec&&) noexcept;
    strVec& operator=(strVec&&) noexcept;
    ~strVec() { free(); }

    std::string* begin() const { return firstElem;}
    std::string* end() const {return firstFree; }
    size_t size() const {return firstFree-firstElem;}
    size_t capacity() const {return finalElem - firstElem; }
    void reserve(size_t n) { if(n > capacity()) reallocate(n); }
    void resize(size_t, const std::string& = std::string());
    void push_back(const std::string&);
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


#endif // STRVEC
