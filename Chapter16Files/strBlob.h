#ifndef STRBLOB
#define STRBLOB

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

//naturally it makes sense for the pointers to be defined along with the object, so I included the pointers
//in the same header file

class strBlobPtr;
class strBlobPtrConst;

class strBlob{
public:
    typedef std::vector<std::string>::size_type index;

    friend class strBlobPtr;
    friend class strBlobPtrConst;
    friend bool operator==(const strBlob&, const strBlob&);
    friend bool operator!=(const strBlob&, const strBlob&);
    friend bool operator<(const strBlob&, const strBlob&);
    friend bool operator>(const strBlob&, const strBlob&);
    friend bool operator<=(const strBlob&, const strBlob&);
    friend bool operator>=(const strBlob&, const strBlob&);

    strBlob();
    strBlob(std::initializer_list<std::string>);

    std::string& operator[](size_t n);
    const std::string& operator[](size_t n) const;

    index size() const { return data->size();}
    bool empty() const { return data->empty();}
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
    strBlobPtr begin();
    strBlobPtr end();
    strBlobPtrConst cbegin() const;
    strBlobPtrConst cend() const;
    void push_back(const std::string& str) { data->push_back(str);};
    void pop_back();

private:
    void check(index, const std::string&) const;

    std::shared_ptr<std::vector<std::string>> data;

};

bool operator==(const strBlob&, const strBlob&);
bool operator!=(const strBlob&, const strBlob&);
bool operator<(const strBlob&, const strBlob&);
bool operator>(const strBlob&, const strBlob&);
bool operator<=(const strBlob&, const strBlob&);
bool operator>=(const strBlob&, const strBlob&);











class strBlobPtr{
public:
    typedef strBlob::index index;
    typedef std::vector<std::string>::difference_type difference_type;

    friend bool operator==(const strBlobPtr&, const strBlobPtr&);
    friend bool operator<(const strBlobPtr&, const strBlobPtr&);
    friend strBlobPtr::difference_type operator-(const strBlobPtr&, const strBlobPtr&);

    strBlobPtr(): curr(0) { }
    strBlobPtr(strBlob& a, index b = 0): ptr(a.data), curr(b) { }

    std::string& operator[](index n) const;
    strBlobPtr& operator++();
    strBlobPtr& operator--();
    strBlobPtr operator++(int);
    strBlobPtr operator--(int);
    strBlobPtr& operator+=(const index&);
    strBlobPtr& operator-=(const index&);
    std::string& operator*() const;
    std::string* operator->() const;

private:
    std::shared_ptr<std::vector<std::string>> check(index, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> ptr;
    index curr;

};

bool operator==(const strBlobPtr&, const strBlobPtr&);
bool operator!=(const strBlobPtr&, const strBlobPtr&);
bool operator<(const strBlobPtr&, const strBlobPtr&);
bool operator>(const strBlobPtr&, const strBlobPtr&);
bool operator<=(const strBlobPtr&, const strBlobPtr&);
bool operator>=(const strBlobPtr&, const strBlobPtr&);
strBlobPtr operator+(const strBlobPtr&, const strBlobPtr::index&);
strBlobPtr operator-(const strBlobPtr&, const strBlobPtr::index&);
strBlobPtr::difference_type operator-(const strBlobPtr&, const strBlobPtr&);











class strBlobPtrConst{
public:
    typedef strBlob::index index;
    typedef std::vector<std::string>::difference_type difference_type;

    friend bool operator==(const strBlobPtrConst&, const strBlobPtrConst&);
    friend bool operator<(const strBlobPtrConst&, const strBlobPtrConst&);
    friend strBlobPtrConst::difference_type operator-(const strBlobPtrConst&, const strBlobPtrConst&);

    strBlobPtrConst(): curr(0) { }
    strBlobPtrConst(const strBlob& a, index b = 0): ptr(a.data), curr(b) { }

    const std::string& operator[](index n) const;
    strBlobPtrConst& operator++();
    strBlobPtrConst& operator--();
    strBlobPtrConst operator++(int);
    strBlobPtrConst operator--(int);
    strBlobPtrConst& operator+=(const index&);
    strBlobPtrConst& operator-=(const index&);
    const std::string& operator*() const;
    const std::string* operator->() const;

private:
    std::shared_ptr<std::vector<std::string>> check(index, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> ptr;
    index curr;

};

bool operator==(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator!=(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator<(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator<(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator>(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator<=(const strBlobPtrConst&, const strBlobPtrConst&);
bool operator>=(const strBlobPtrConst&, const strBlobPtrConst&);
strBlobPtrConst operator+(const strBlobPtrConst&, const strBlobPtrConst::index&);
strBlobPtrConst operator-(const strBlobPtrConst&, const strBlobPtrConst::index&);
strBlobPtrConst::difference_type operator-(const strBlobPtrConst&, const strBlobPtrConst&);



#endif // strBlob

