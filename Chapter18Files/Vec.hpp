#ifndef VEC
#define VEC

#include <memory> //allocator type
#include <utility> //pair type and std::move
#include <initializer_list>

template <typename T> class Vec{
public:

    /*Since this is a template there is one thing to consider: free() could throw. Allocator.destroy() destroys each element
    by calling its destructor but since this is a template we don't know whether the template type's destructor could throw.
    One could make a compile time check for this, but the assumption is that the the destructor of any type supplied will not
    throw since this is a bad idea anyway. Aside from this, everything remains the same as strVec*/

    Vec(): firstElem(nullptr), firstFree(nullptr), finalElem(nullptr) { }
    Vec(const Vec&);
    Vec(std::initializer_list<T>);
    Vec& operator=(const Vec&);
    Vec(Vec&&) noexcept;
    Vec& operator=(Vec&&) noexcept;
    ~Vec() { free(); }

    T* begin() const { return firstElem;}
    T* end() const {return firstFree; }
    size_t size() const {return firstFree-firstElem;}
    size_t capacity() const {return finalElem - firstElem; }
    void reserve(size_t n) { if(n > capacity()) reallocate(n); }
    void resize(size_t, const T& = T());
    void push_back(const T&);
    template <typename... Args> void emplace_back(Args&&...);
private:
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void check_n_alloc();
    void reallocate(size_t);
    void free();
    std::allocator<T> alloc;
    T* firstElem;
    T* firstFree;
    T* finalElem;

};

template <typename T> Vec<T>::Vec(const Vec& rhs){
    auto IterPairs = alloc_n_copy(rhs.begin(), rhs.end()); //I think this plays out alright if rhs is all nullpointers
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

template <typename T> Vec<T>::Vec(Vec&& rhs) noexcept: firstElem(rhs.firstElem), firstFree(rhs.firstFree), finalElem(rhs.finalElem) {
    rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
}

template <typename T> Vec<T>::Vec(std::initializer_list<T> li) {
    auto IterPairs = alloc_n_copy(li.begin(), li.end());
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec<T>& rhs){
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    firstElem = newData.first;
    firstFree = newData.second;
    finalElem = firstFree;
    return *this;
}

template <typename T> Vec<T>& Vec<T>::operator=(Vec<T>&& rhs) noexcept {
    if(this != &rhs){
        free();
        firstElem = rhs.firstElem;
        firstFree = rhs.firstFree;
        finalElem = rhs.finalElem;
        rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
    }
    return *this;
}

template <typename T> void Vec<T>::resize(size_t n, const T& s){
    if(size() != n){
        reallocate(n);
        while(size() != n) //if n<size() originally then n == size() at this stage
            alloc.construct(firstFree++, s);
    }
}

template <typename T> void Vec<T>::push_back(const T& s){
    check_n_alloc();
    alloc.construct(firstFree++, s);
}

template <typename T> template <typename... Args> inline void Vec<T>::emplace_back(Args&&... args){
    check_n_alloc();
    alloc.construct(firstFree++, std::forward<Args>(args)...);
}

template <typename T> std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* begin, const T* end){
    auto beginAlloc = alloc.allocate(end-begin);
    return {beginAlloc, uninitialized_copy(begin, end, beginAlloc)};
}

template <typename T> void Vec<T>::check_n_alloc(){
    if(firstFree == finalElem)
        reallocate((size() ? 2*size() : 1));
}

template <typename T> void Vec<T>::reallocate(size_t n){
    auto newCapacity = n;
    auto newFirstElem = alloc.allocate(newCapacity);
    auto newFirstFree = uninitialized_copy_n(make_move_iterator(firstElem), (n > size() ? size() : n), newFirstElem);

    free();

    firstElem = newFirstElem;
    firstFree = newFirstFree;
    finalElem = newFirstElem + newCapacity;
}

template <typename T> void Vec<T>::free(){
    if(finalElem){ //since we can't call deallocate on a nullptr
        //for_each(firstFree, firstElem, [this](string& s) { alloc.destroy(&s); });
        for(auto it = firstFree; it != firstElem; )
            alloc.destroy(--it);
        alloc.deallocate(firstElem, finalElem-firstElem);
    }
}


#endif // Vec
