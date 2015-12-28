#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include "strBlob.h"

using namespace std;

strBlob::strBlob(): data(make_shared<vector<string>>()) { }
strBlob::strBlob(initializer_list<string> lis): data(make_shared<vector<string>>(lis)) { }

string& strBlob::front(){
    check(0, "Front function called on empty strBlob.");
    return data->front();
}

const string& strBlob::front() const {
    check(0, "Front function called on empty strBlob.");
    return data->front();
}

string& strBlob::back(){
    check(0, "Back function called on empty strBlob.");
    return data->back();
}

const string& strBlob::back() const {
    check(0, "Back function called on empty strBlob.");
    return data->back();
}

strBlobPtr strBlob::begin() {
    return strBlobPtr(*this);
}

strBlobPtr strBlob::end() {
    return strBlobPtr(*this, data->size());
}

strBlobPtrConst strBlob::cbegin() const {
    return strBlobPtrConst(*this);
}

strBlobPtrConst strBlob::cend() const {
    return strBlobPtrConst(*this, data->size());
}

void strBlob::pop_back() {
    check(0, "Pop_Back function called on empty strBlob.");
    data->pop_back();
}

void strBlob::check(index i, const string& msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}






string& strBlobPtr::deref() const {
    auto p = check(curr, "Out of range error while dereferencing.");
    return (*p)[curr];
}

strBlobPtr& strBlobPtr::increment() {
    check(curr, "Current position is one past the last element. Cannot increment further.");
    ++curr;
    return (*this);
}

shared_ptr<vector<string>> strBlobPtr::check(index i, const string& c) const {
    auto ret = ptr.lock();
    if(!ret)
        throw runtime_error("Underlying strBlob object no longer exists.");
    else if(i >= (ret->size()))
        throw out_of_range(c);
    return ret;
}






const string& strBlobPtrConst::deref() const {
    auto p = check(curr, "Out of range error while dereferencing.");
    return (*p)[curr];
}

strBlobPtrConst& strBlobPtrConst::increment() {
    check(curr, "Current position is one past the last element. Cannot increment further.");
    ++curr;
    return (*this);
}

shared_ptr<vector<string>> strBlobPtrConst::check(index i, const string& c) const {
    auto ret = ptr.lock();
    if(!ret)
        throw runtime_error("Underlying strBlob object no longer exists.");
    else if(i >= (ret->size()))
        throw out_of_range(c);
    return ret;
}


