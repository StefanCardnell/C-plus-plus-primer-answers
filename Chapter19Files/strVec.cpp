#include "strVec.h"
#include <utility> //for std::move


using namespace std;

strVec::strVec(const strVec& rhs){
    auto IterPairs = alloc_n_copy(rhs.begin(), rhs.end()); //I think this plays out alright if rhs is all nullpointers
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

strVec::strVec(strVec&& rhs) noexcept: firstElem(rhs.firstElem), firstFree(rhs.firstFree), finalElem(rhs.finalElem) {
    rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
}

strVec::strVec(std::initializer_list<std::string> li) {
    auto IterPairs = alloc_n_copy(li.begin(), li.end());
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

strVec& strVec::operator=(const strVec& rhs){
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    firstElem = newData.first;
    firstFree = newData.second;
    finalElem = firstFree;
    return *this;
}

strVec& strVec::operator=(strVec&& rhs) noexcept {
    if(this != &rhs){
        free();
        firstElem = rhs.firstElem;
        firstFree = rhs.firstFree;
        finalElem = rhs.finalElem;
        rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
    }
    return *this;
}

void strVec::resize(size_t n, const string& s){
    if(size() != n){
        reallocate(n);
        while(size() != n) //if n<size() originally then n == size() at this stage
            alloc.construct(firstFree++, s);
    }
}

void strVec::push_back(const string& s){
    check_n_alloc();
    alloc.construct(firstFree++, s);
}

pair<string*, string*> strVec::alloc_n_copy(const string* begin, const string* end){
    auto beginAlloc = alloc.allocate(end-begin);
    return {beginAlloc, uninitialized_copy(begin, end, beginAlloc)};
}

void strVec::check_n_alloc(){
    if(firstFree == finalElem)
        reallocate((size() ? 2*size() : 1));
}

void strVec::reallocate(size_t n){
    auto newCapacity = n;
    auto newFirstElem = alloc.allocate(newCapacity);
    auto newFirstFree = uninitialized_copy_n(make_move_iterator(firstElem), (n > size() ? size() : n), newFirstElem);

    free();

    firstElem = newFirstElem;
    firstFree = newFirstFree;
    finalElem = newFirstElem + newCapacity;
}

void strVec::free(){
    if(finalElem){ //since we can't call deallocate on a nullptr
        //for_each(firstFree, firstElem, [this](string& s) { alloc.destroy(&s); });
        for(auto it = firstFree; it != firstElem; )
            alloc.destroy(--it);
        alloc.deallocate(firstElem, finalElem-firstElem);
    }
}
