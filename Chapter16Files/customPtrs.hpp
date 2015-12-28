#ifndef CUSTOMPTRS
#define CUSTOMPTRS

#include <cstddef> //nullptr_t
#include <functional> //for function<T>
#include "DebugDelete.hpp"

/* Right now there is an error: If a function pointer is supplied as a template type
   but the function pointer is not supplied in a constructor, then del will be a
   nullptr which could be called as a deleter.
   This class works on the assumption that operator() makes sense on all uniquePtr
   objects except those that have been moved from. */

/* Ultimately it is hard to strive for perfection in this question. To consider every error
   and incorporate all complexities would require an effort akin to the actual unique_ptr
   and shared_ptr definitions. I will just have to accept that these definitions are flawed
   in certain special cases. These flaws are, as I've noticed:

   1) The error as mentioned above.
   2) The inability to use low-level non-const pointers in places where low-level const pointers
      are expected (especially in the copy/move operations).
   3) The lack of move operations for the deleter creates type-errors in the corresponding unique_ptr
      operations and also prevents the use of std::swap. */


template <typename> class sharedPtr;
template <typename, typename> class uniquePtr;
template <typename T, typename D> void swap(uniquePtr<T,D>&, uniquePtr<T,D>&);

template <typename T, typename D = DebugDelete> class uniquePtr{
    friend void swap<T, D>(uniquePtr<T,D>&, uniquePtr<T,D>&);
    friend class sharedPtr<T>;
public:
    //constructors: one default and two custom
    uniquePtr() = default;
    explicit uniquePtr(T* p): ptr(p) { }
    uniquePtr(T* p, D d): ptr(p), del(d) { }

    //copy operations deleted
    uniquePtr(const uniquePtr&) = delete;
    uniquePtr& operator=(const uniquePtr&) = delete;

    //move operations: not marked as noexcept since it is unknown whether move of del will throw.
    uniquePtr(uniquePtr&& rhs): ptr(std::move(rhs.ptr)), del(std::move(rhs.del)) { rhs.ptr = nullptr;}
    uniquePtr& operator=(uniquePtr&&);

    //assignment from nullptr shall delete uniquePtr's object and assign to nullptr
    uniquePtr& operator=(std::nullptr_t n) { reset(); return *this;}

    //destructor does work only if ptr is not null (error: del could be a null function pointer)
    ~uniquePtr(){ if(ptr) del(ptr);}

    explicit operator bool() const { return ptr; }

    T& operator*() const { return *ptr;}
    T* operator->() const { return ptr;}

    T* get() const {return ptr;}
    T* release();
    void reset(T* q = nullptr){ if(ptr) del(ptr); ptr = q;}
    void swap(uniquePtr& rhs) { ::swap(*this, rhs);}

private:
    T* ptr = nullptr;
    D del = D();
};

template <typename T, typename D> inline void swap(uniquePtr<T,D>& lhs, uniquePtr<T,D>& rhs){
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.del, rhs.del);
}

template <typename T, typename D> inline uniquePtr<T,D>& uniquePtr<T,D>::operator=(uniquePtr&& rhs) {
    if(this != &rhs){
        if(ptr) del(ptr);
        ptr = std::move(rhs.ptr);
        del = std::move(rhs.del);
        rhs.ptr = nullptr;
    }
    return *this;
}

template <typename T, typename D> inline T* uniquePtr<T,D>::release(){
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}




template <typename T> void swap(sharedPtr<T>&, sharedPtr<T>&);

template <typename T> class sharedPtr{
    friend void swap<T>(sharedPtr<T>&, sharedPtr<T>&);
public:
    //constructors
    sharedPtr(): cnt(new size_t(1)) { }
    explicit sharedPtr(T* p): cnt(new size_t(1)), ptr(p) { }
    template <typename D> sharedPtr(uniquePtr<T,D>&& rhs): cnt(new size_t(1)), ptr(std::move(rhs.ptr)), del(std::move(rhs.del)) { rhs.ptr = nullptr;}
    template <typename D> sharedPtr(T* p, D d): cnt(new size_t(1)), ptr(p), del(d) { }

    //copy operations
    sharedPtr(const sharedPtr& rhs): cnt(rhs.cnt), ptr(rhs.ptr), del(rhs.del) { ++*cnt;}
    sharedPtr& operator=(const sharedPtr&);

    //move operations
    sharedPtr& operator=(sharedPtr&&);
    sharedPtr(sharedPtr&& rhs): cnt(std::move(rhs.cnt)), ptr(std::move(rhs.ptr)), del(std::move(rhs.del)) { rhs.cnt = new size_t(1); rhs.ptr = nullptr; }

    //destructor
    ~sharedPtr();

    explicit operator bool() const { return ptr;}

    T& operator*() const { return *ptr;}
    T* operator->() const { return ptr;}

    T* get() const {return ptr;}
    bool unique() const {return !(*cnt);}
    size_t use_count() const { return *cnt;}
    template <typename D> void reset(T* p = nullptr, D d = nullptr);
    void swap(sharedPtr& rhs) { ::swap(*this, rhs);}

private:
    void decrement_and_delete() const;
    size_t* cnt;
    T* ptr = nullptr;
    std::function<void(T*)> del;

};

template <typename T> inline void swap(sharedPtr<T>& lhs, sharedPtr<T>& rhs){
    using std::swap;
    swap(lhs.cnt, rhs.cnt);
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.del, rhs.del);
}

template <typename T> inline sharedPtr<T>& sharedPtr<T>::operator=(const sharedPtr& rhs){
    ++*rhs.cnt;
    decrement_and_delete();
    cnt = rhs.cnt;
    ptr = rhs.ptr;
    del = rhs.del;
    return *this;
}


template <typename T> inline sharedPtr<T>& sharedPtr<T>::operator=(sharedPtr&& rhs){ //cannot be marked as noexcept since heap allocation could throw
    if(this != &rhs){
        decrement_and_delete();
        cnt = std::move(rhs.cnt);
        ptr = std::move(rhs.ptr);
        del = std::move(rhs.del);
        rhs.cnt = new size_t(1);
        rhs.ptr = nullptr;
    }
    return *this;
}

template <typename T> inline sharedPtr<T>::~sharedPtr(){
    decrement_and_delete();//works fine if this was a moved-from object (ptr will evaluate as false)
}

template <typename T> template <typename D> inline void sharedPtr<T>::reset(T* p, D d){
    if(ptr != p){
        decrement_and_delete();
        cnt = new int(1);
        ptr = p;
    }
    del = d;
}

template <typename T> inline void sharedPtr<T>::decrement_and_delete() const {
    if(--*cnt == 0){
        if(ptr) del ? del(ptr) : delete ptr;
        delete cnt;
    }
}






#endif // UNIQUEPTR
