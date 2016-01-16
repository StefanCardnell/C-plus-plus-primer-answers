#ifndef BLOB
#define BLOB

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <exception>
#include <new> //bad_alloc

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> class BlobPtrConst;

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    friend class BlobPtr<T>;
    friend class BlobPtrConst<T>;
    friend bool operator== <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);

    Blob();
    template <typename It> Blob(It b, It e);
    Blob(std::initializer_list<T> li);

    T& operator[](size_type);
    const T& operator[](size_type) const;

    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    BlobPtr<T> begin();
    BlobPtr<T> end();
    BlobPtrConst<T> begin() const;
    BlobPtrConst<T> end() const;

    BlobPtrConst<T> cbegin() const;
    BlobPtrConst<T> cend() const;

    void push_back(const T& v) {data->push_back(v);}
    void pop_back();

private:
    void check(size_type, const std::string&) const;
    std::shared_ptr<std::vector<T>> data;

};


template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> typename BlobPtr<T>::difference_type operator-(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr {
public:
    typedef typename std::vector<T>::difference_type difference_type;
    typedef typename Blob<T>::size_type size_type;

    friend bool operator== <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend difference_type operator- <T>(const BlobPtr<T>&, const BlobPtr<T>&);

    /*can't see how these would need function-try blocks. There is no way they could throw an error.
    As a result, they are declared as noexcept*/

    BlobPtr() noexcept : curr(0) { }
    BlobPtr(Blob<T>& a, size_type i = 0) noexcept : curr(i), ptr(a.data)  { }

    T& operator[](size_type i) const;
    BlobPtr<T>& operator++();
    BlobPtr<T>& operator--();
    BlobPtr<T> operator++(int);
    BlobPtr<T> operator--(int);

    BlobPtr<T>& operator+=(size_type);
    BlobPtr<T>& operator-=(size_type);
    T& operator*() const;
    T* operator->() const;

private:
    std::shared_ptr<std::vector<T>> check(size_type, const std::string&) const;

    size_type curr;
    std::weak_ptr<std::vector<T>> ptr;

};




template <typename T> bool operator==(const BlobPtrConst<T>&, const BlobPtrConst<T>&);
template <typename T> bool operator<(const BlobPtrConst<T>&, const BlobPtrConst<T>&);
template <typename T> typename BlobPtrConst<T>::difference_type operator-(const BlobPtrConst<T>&, const BlobPtrConst<T>&);

template <typename T> class BlobPtrConst {
public:
    typedef typename std::vector<T>::difference_type difference_type;
    typedef typename Blob<T>::size_type size_type;

    friend bool operator== <T>(const BlobPtrConst<T>&, const BlobPtrConst<T>&);
    friend bool operator< <T>(const BlobPtrConst<T>&, const BlobPtrConst<T>&);
    friend difference_type operator- <T>(const BlobPtrConst<T>&, const BlobPtrConst<T>&);

    /*can't see how these would need function-try blocks. There is no way they could throw an error.
    As a result, they are declared as noexcept*/

    BlobPtrConst() noexcept : curr(0) { }
    BlobPtrConst(const Blob<T>& a, size_type i = 0) noexcept : curr(i), ptr(a.data) { }

    const T& operator[](size_type i) const;
    BlobPtrConst<T>& operator++();
    BlobPtrConst<T>& operator--();
    BlobPtrConst<T> operator++(int);
    BlobPtrConst<T> operator--(int);

    BlobPtrConst<T>& operator+=(size_type);
    BlobPtrConst<T>& operator-=(size_type);
    const T& operator*() const;
    const T* operator->() const;

private:
    std::shared_ptr<std::vector<T>> check(size_type, const std::string&) const;

    size_type curr;
    std::weak_ptr<std::vector<T>> ptr;

};






template <typename T> bool operator==(const Blob<T>& lhs, const Blob<T>& rhs){
    return (*lhs.data == *rhs.data);
}

template <typename T> bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs){
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T>& lhs, const Blob<T>& rhs){
    return (*lhs.data < *rhs.data);
}

template <typename T> bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs){
    return !(rhs < lhs);
}

template <typename T> bool operator>(const Blob<T>& lhs, const Blob<T>& rhs){
    return (rhs < lhs);
}

template <typename T> bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs){
    return !(lhs < rhs);
}

/*Three errors to consider: The two bad_allocs that may occur either during the vector allocation or the allocation of its elements. Then
there could be any error that occurs when creating the vector elements (since we don't know the type of the element T which would throw).
In this latter case the vector is destroyed and the error passed up.*/

template <typename T> Blob<T>::Blob() try : data(std::make_shared<std::vector<T>>()){
    } catch(const std::bad_alloc& err){ std::cout << "Bad allocation error either during Vector or Vector element allocation in function " << __func__ << "." << std::endl; throw;
    } catch(const std::exception& err) { std::cout << "Unspecified exception caught during Blob construction." << std::endl; throw;}

template <typename T> template <typename It> Blob<T>::Blob(It b, It e) try : data(std::make_shared<std::vector<T>>(b,e)) {
    } catch(const std::bad_alloc& err){ std::cout << "Bad allocation error either during Vector or Vector element allocation in function " << __func__ << "." << std::endl; throw;
    } catch(const std::exception& err) { std::cout << "Unspecified exception caught during Blob construction." << std::endl; throw;}

template <typename T> Blob<T>::Blob(std::initializer_list<T> li) try : data(std::make_shared<std::vector<T>>(li)) {
    } catch(const std::bad_alloc& err){ std::cout << "Bad allocation error either during Vector or Vector element allocation in function " << __func__ << "." << std::endl; throw;
    } catch(const std::exception& err) { std::cout << "Unspecified exception caught during Blob construction." << std::endl; throw;}

template <typename T> T& Blob<T>::operator[](size_type i){
    check(i, "Index i for operator[] out of Blob range.");
    return (*data)[i];
}

template <typename T> const T& Blob<T>::operator[](size_type i) const {
    check(i, "Index i for operator[] out of Blob range.");
    return (*data)[i];
}

template <typename T> T& Blob<T>::front(){
    check(0, "Front() called on empty Blob.");
    return data->front();
}

template <typename T> const T& Blob<T>::front() const{
    check(0, "Front() called on empty Blob.");
    return data->front();
}

template <typename T> T& Blob<T>::back(){
    check(0, "Back() called on empty Blob.");
    return data->back();
}

template <typename T> const T& Blob<T>::back() const{
    check(0, "Back() called on empty Blob.");
    return data->back();
}

template <typename T> BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}

template <typename T> BlobPtrConst<T> Blob<T>::begin() const {
    return BlobPtrConst<T>(*this);
}

template <typename T> BlobPtrConst<T> Blob<T>::end() const {
    return BlobPtrConst<T>(*this, data->size());
}

template <typename T> BlobPtrConst<T> Blob<T>::cbegin() const {
    return BlobPtrConst<T>(*this);
}

template <typename T> BlobPtrConst<T> Blob<T>::cend() const {
    return BlobPtrConst<T>(*this, data->size());
}

template <typename T> void Blob<T>::pop_back(){
    check(0, "Pop_back() called on empty Blob.");
    data->pop_back();
}

template <typename T> void Blob<T>::check(size_type i, const std::string& msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}










template <typename T> bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return (lhs.curr == rhs.curr); //it is up to the user to make sure the iterators point to the same container
}

template <typename T> bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return !(lhs == rhs); //it is up to the user to make sure the iterators point to the same container
}

template <typename T> bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return (lhs.curr < rhs.curr);
}

template <typename T> bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return (rhs < lhs);
}

template <typename T> bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return !(rhs < lhs);
}

template <typename T> bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return !(lhs < rhs);
}

template <typename T> T& BlobPtr<T>::operator[](size_type i) const{
    auto ret = check(curr+i, "Attempt to dereference past the end of Blob.");
    return (*ret)[curr+i];

}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++(){
    check(curr, "Increment past the end.");
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--(){
    check(curr-1, "Increment past the end.");
    --curr;
    return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator+=(size_type i){
    curr += i;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator-=(size_type i){
    curr -= i;
    return *this;
}

template <typename T> T& BlobPtr<T>::operator*() const {
    auto ret = check(curr, "Attempt to dereference past the end of Blob.");
    return (*ret)[curr];
}

template <typename T> T* BlobPtr<T>::operator->() const {
    return &(this->operator*());
}

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string& msg) const {
    auto ret = ptr.lock();
    if(!ret) throw std::runtime_error("Blob pointed to by BlobPtr no longer exists.");
    else if(ret->size() <= i) throw std::out_of_range(msg);
    return ret;
}

template <typename T> BlobPtr<T> operator+(const BlobPtr<T>& lhs, typename BlobPtr<T>::size_type rhs){
    BlobPtr<T> ret = lhs;
    ret += rhs;
    return ret;
}

template <typename T> BlobPtr<T> operator-(const BlobPtr<T>& lhs, typename BlobPtr<T>::size_type rhs){
    BlobPtr<T> ret = lhs;
    ret -= rhs;
    return ret;
}

template <typename T> typename BlobPtr<T>::difference_type operator-(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    if(lhs.curr >= rhs.curr) return static_cast<typename BlobPtr<T>::difference_type>(lhs.curr-rhs.curr);
    else return -static_cast<typename BlobPtr<T>::difference_type>(rhs.curr-lhs.curr);;
}











template <typename T> bool operator==(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return (lhs.curr == rhs.curr); //it is up to the user to make sure the iterators point to the same container
}

template <typename T> bool operator!=(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return !(lhs == rhs); //it is up to the user to make sure the iterators point to the same container
}

template <typename T> bool operator<(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return (lhs.curr < rhs.curr);
}

template <typename T> bool operator>(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return (rhs < lhs);
}

template <typename T> bool operator<=(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return !(rhs < lhs);
}

template <typename T> bool operator>=(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    return !(lhs < rhs);
}

template <typename T> const T& BlobPtrConst<T>::operator[](size_type i) const {
    auto ret = check(curr+i, "Attempt to dereference past the end of Blob.");
    return (*ret)[curr+i];

}

template <typename T> BlobPtrConst<T>& BlobPtrConst<T>::operator++(){
    check(curr, "Increment past the end.");
    ++curr;
    return *this;
}

template <typename T> BlobPtrConst<T>& BlobPtrConst<T>::operator--(){
    check(curr-1, "Increment past the end.");
    --curr;
    return *this;
}

template <typename T> BlobPtrConst<T> BlobPtrConst<T>::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T> BlobPtrConst<T> BlobPtrConst<T>::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T> BlobPtrConst<T>& BlobPtrConst<T>::operator+=(size_type i){
    curr += i;
    return *this;
}

template <typename T> BlobPtrConst<T>& BlobPtrConst<T>::operator-=(size_type i){
    curr -= i;
    return *this;
}

template <typename T> const T& BlobPtrConst<T>::operator*() const {
    auto ret = check(curr, "Attempt to dereference past the end of Blob.");
    return (*ret)[curr];
}

template <typename T> const T* BlobPtrConst<T>::operator->() const {
    return &(this->operator*());
}

template <typename T> std::shared_ptr<std::vector<T>> BlobPtrConst<T>::check(size_type i, const std::string& msg) const {
    auto ret = ptr.lock();
    if(!ret) throw std::runtime_error("Blob pointed to by BlobPtrConst no longer exists.");
    else if(ret->size() <= i) throw std::out_of_range(msg);
    return ret;

}

template <typename T> BlobPtrConst<T> operator+(const BlobPtrConst<T>& lhs, typename BlobPtrConst<T>::size_type rhs){
    BlobPtrConst<T> ret = lhs;
    ret += rhs;
    return ret;
}

template <typename T> BlobPtrConst<T> operator-(const BlobPtrConst<T>& lhs, typename BlobPtrConst<T>::size_type rhs){
    BlobPtrConst<T> ret = lhs;
    ret -= rhs;
    return ret;
}

template <typename T> typename BlobPtrConst<T>::difference_type operator-(const BlobPtrConst<T>& lhs, const BlobPtrConst<T>& rhs){
    if(lhs.curr >= rhs.curr) return static_cast<typename BlobPtrConst<T>::difference_type>(lhs.curr-rhs.curr);
    else return -static_cast<typename BlobPtrConst<T>::difference_type>(rhs.curr-lhs.curr);;
}


#endif // BLOB
