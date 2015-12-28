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
    friend class strBlobPtr;
    friend class strBlobPtrConst;
public:
    typedef std::vector<std::string>::size_type index;

    strBlob();
    strBlob(std::initializer_list<std::string>);

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
    std::shared_ptr<std::vector<std::string>> data;
    void check(index, const std::string&) const;


};

class strBlobPtr{
public:
    typedef strBlob::index index;
    strBlobPtr(): curr(0) { }
    strBlobPtr(strBlob& a, index b = 0): ptr(a.data), curr(b) { }

    std::string& deref() const;
    strBlobPtr& increment();

private:
    std::shared_ptr<std::vector<std::string>> check(index, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> ptr;
    index curr;

};


class strBlobPtrConst{
public:
    typedef strBlob::index index;
    strBlobPtrConst(): curr(0) { }
    strBlobPtrConst(const strBlob& a, index b = 0): ptr(a.data), curr(b) { }

    const std::string& deref() const;
    strBlobPtrConst& increment();

private:
    std::shared_ptr<std::vector<std::string>> check(index, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> ptr;
    index curr;

};




#endif // strBlob

