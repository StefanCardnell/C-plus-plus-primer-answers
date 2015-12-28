#ifndef BLOBPTR
#define BLOBPTR

#include <vector>
#include <string>
#include <initializer_list>
#include "customPtrs.hpp"

template <typename T> class Blob;

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    friend bool operator== <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);

    Blob(): data(sharedPtr<std::vector<T>>(new std::vector<T>())) { }
    template <typename It> Blob(It b, It e): data(sharedPtr<std::vector<T>>(new std::vector<T>(b,e))) { }
    Blob(std::initializer_list<T> li): data(sharedPtr<std::vector<T>>(new std::vector<T>(li))) { }

    T& operator[](size_type);
    const T& operator[](size_type) const;

    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_back(const T& v) {data->push_back(v);}
    void pop_back();

private:
    void check(size_type, const std::string&) const;
    sharedPtr<std::vector<T>> data;

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

template <typename T> void Blob<T>::pop_back(){
    check(0, "Pop_back() called on empty Blob.");
    data->pop_back();
}

template <typename T> void Blob<T>::check(size_type i, const std::string& msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}

#endif // BLOB
