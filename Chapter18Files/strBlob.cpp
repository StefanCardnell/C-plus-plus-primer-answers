#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include "strBlob.h"

using namespace std;

strBlob::strBlob(): data(make_shared<vector<string>>()) { }
strBlob::strBlob(initializer_list<string> lis): data(make_shared<vector<string>>(lis)) { }

std::string& strBlob::operator[](size_t n){
    check(n, "Out of range when subscripting.");
    return (*data)[n];
}

const std::string& strBlob::operator[](size_t n) const {
    check(n, "Out of range  when subscripting.");
    return (*data)[n];
}

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

bool operator==(const strBlob& lhs, const strBlob& rhs){
    return (*lhs.data == *rhs.data); //strBlob is a vector basically, and it should equate like a vector
}

bool operator!=(const strBlob& lhs, const strBlob& rhs){
    return !(lhs == rhs);
}

bool operator<(const strBlob& lhs, const strBlob& rhs){
    return (*lhs.data < *rhs.data);
}

bool operator>(const strBlob& lhs, const strBlob& rhs){
    return (rhs < lhs);
}

bool operator<=(const strBlob& lhs, const strBlob& rhs){
    return !(rhs < lhs);
}

bool operator>=(const strBlob& lhs, const strBlob& rhs){
    return !(lhs < rhs);
}














std::string& strBlobPtr::operator[](index n) const {
    auto p = check(curr+n, "Out of range error while subscripting.");
    return (*p)[curr+n];
}

strBlobPtr& strBlobPtr::operator++(){
    check(curr, "Increment past the end.");
    ++curr;
    return *this;
}

strBlobPtr& strBlobPtr::operator--(){
    check(curr-1, "Decrement past the end.");
    --curr;
    return *this;
}

strBlobPtr strBlobPtr::operator++(int){
    strBlobPtr old = *this;
    ++*this;
    return old;
}

strBlobPtr strBlobPtr::operator--(int){
    strBlobPtr old = *this;
    --*this;
    return old;
}

string& strBlobPtr::operator*() const {
    auto p = check(curr, "Dereference past end of container.");
    return (*p)[curr];
}

string* strBlobPtr::operator->() const {
    return &(this->operator*());
}

shared_ptr<vector<string>> strBlobPtr::check(index i, const string& c) const {
    auto ret = ptr.lock();
    if(!ret)
        throw runtime_error("Underlying strBlob object no longer exists.");
    else if(i >= (ret->size()))
        throw out_of_range(c);
    return ret;
}

bool operator==(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return (lhs.curr == rhs.curr); //it is up to the user to make sure the iterators point to the same container
}

bool operator!=(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return !(lhs == rhs);
}

bool operator<(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return (lhs.curr < rhs.curr);
}

bool operator>(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return (rhs < lhs);
}

bool operator<=(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return !(rhs < lhs);
}

bool operator>=(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return !(lhs < rhs);
}

strBlobPtr operator+(const strBlobPtr& lhs, const strBlobPtr::index& rhs){
    strBlobPtr ret = lhs;
    ret += rhs;
    return ret;
}

strBlobPtr operator-(const strBlobPtr& lhs, const strBlobPtr::index& rhs){
    strBlobPtr ret = lhs;
    ret -= rhs;
    return ret;
}

strBlobPtr& strBlobPtr::operator+=(const strBlobPtr::index& rhs){
    curr += rhs;
    return *this;
}

strBlobPtr& strBlobPtr::operator-=(const strBlobPtr::index& rhs){
    curr -= rhs;
    return *this;
}

strBlobPtr::difference_type operator-(const strBlobPtr& lhs, const strBlobPtr& rhs){
    if(lhs.curr >= rhs.curr) return static_cast<strBlobPtr::difference_type>(lhs.curr-rhs.curr);
    else return -static_cast<strBlobPtr::difference_type>(rhs.curr-lhs.curr);
}















const std::string& strBlobPtrConst::operator[](index n) const {
    auto p = check(curr+n, "Out of range error while subscripting.");
    return (*p)[curr+n];
}

strBlobPtrConst& strBlobPtrConst::operator++(){
    check(curr, "Increment past the end.");
    ++curr;
    return *this;
}

strBlobPtrConst& strBlobPtrConst::operator--(){
    check(curr-1, "Decrement past the end.");
    --curr;
    return *this;
}

strBlobPtrConst strBlobPtrConst::operator++(int){
    strBlobPtrConst old = *this;
    ++*this;
    return old;
}

strBlobPtrConst strBlobPtrConst::operator--(int){
    strBlobPtrConst old = *this;
    --*this;
    return old;
}

const string& strBlobPtrConst::operator*() const {
    auto p = check(curr, "Dereference past end of container.");
    return (*p)[curr];
}

const string* strBlobPtrConst::operator->() const {
    return &(this->operator*());
}

shared_ptr<vector<string>> strBlobPtrConst::check(index i, const string& c) const {
    auto ret = ptr.lock();
    if(!ret)
        throw runtime_error("Underlying strBlob object no longer exists.");
    else if(i >= (ret->size()))
        throw out_of_range(c);
    return ret;
}

bool operator==(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return (lhs.curr == rhs.curr);
}

bool operator!=(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return !(lhs == rhs);
}

bool operator<(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return (lhs.curr < rhs.curr);
}

bool operator>(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return (rhs < lhs);
}

bool operator<=(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return !(rhs < lhs);
}

bool operator>=(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    return !(lhs < rhs);
}

strBlobPtrConst operator+(const strBlobPtrConst& lhs, const strBlobPtrConst::index& rhs){
    strBlobPtrConst ret = lhs;
    ret += rhs;
    return ret;
}

strBlobPtrConst operator-(const strBlobPtrConst& lhs, const strBlobPtrConst::index& rhs){
    strBlobPtrConst ret = lhs;
    ret -= rhs;
    return ret;
}

strBlobPtrConst& strBlobPtrConst::operator+=(const strBlobPtrConst::index& rhs){
    curr += rhs;
    return *this;
}

strBlobPtrConst& strBlobPtrConst::operator-=(const strBlobPtrConst::index& rhs){
    curr -= rhs;
    return *this;
}

strBlobPtrConst::difference_type operator-(const strBlobPtrConst& lhs, const strBlobPtrConst& rhs){
    if(lhs.curr >= rhs.curr) return static_cast<strBlobPtrConst::difference_type>(lhs.curr-rhs.curr);
    else return -static_cast<strBlobPtrConst::difference_type>(rhs.curr-lhs.curr);
}

