#include "String.h"
#include <iostream>

using namespace std;

String::String(const String& rhs){
    cout << "Copy Construction" << endl;
    auto IterPairs = alloc_n_copy(rhs.begin(), rhs.end()); //I think this plays out alright if rhs is all nullpointers
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

String::String(const char* rhs){
    cout << "String(const char* rhs)" << endl;
    auto rhsEnd = rhs;
    while(*rhsEnd)
        ++rhsEnd;
    auto IterPairs = alloc_n_copy(rhs, rhsEnd);
    firstElem = IterPairs.first;
    firstFree = IterPairs.second;
    finalElem = firstFree;
}

String& String::operator=(const String& rhs){
    cout << "Copy assignment" << endl;
    auto newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    firstElem = newData.first;
    firstFree = newData.second;
    finalElem = firstFree;
    return *this;
}

String::String(String&& rhs) noexcept: firstElem(rhs.firstElem), firstFree(rhs.firstFree), finalElem(rhs.finalElem) {
    cout << "Move construction" << endl;
    rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
}

String& String::operator=(String&& rhs) noexcept {
    cout << "Move assignment" << endl;
    if(this != &rhs){
        free();
        firstElem = rhs.firstElem;
        firstFree = rhs.firstFree;
        finalElem = rhs.finalElem;
        rhs.firstElem = rhs.firstFree = rhs.finalElem = nullptr;
    }
    return *this;
}

void String::resize(size_t n, const char& s){
    if(size() != n){
        reallocate(n);
        while(size() != n)
            alloc.construct(firstFree++, s); //if n<size() then n == size() at this stage
    }
}

void String::push_back(const char& s){
    check_n_alloc();
    alloc.construct(firstFree++, s);
}

pair<char*, char*> String::alloc_n_copy(const char* begin, const char* end){
    auto beginAlloc = alloc.allocate(end-begin);
    return {beginAlloc, uninitialized_copy(begin, end, beginAlloc)};
}

void String::check_n_alloc(){
    if(firstFree == finalElem)
        reallocate((size() ? 2*size() : 1));
}

void String::reallocate(size_t n){
    auto newCapacity = n;
    auto newFirstElem = alloc.allocate(newCapacity);
    auto newFirstFree = uninitialized_copy_n(firstElem, (n > size() ? size() : n), newFirstElem);

    free();

    firstElem = newFirstElem;
    firstFree = newFirstFree;
    finalElem = newFirstElem + newCapacity;
}

void String::free(){
    if(finalElem){ //since we can't call deallocate on a nullptr
        //for_each(firstFree, firstElem, [this](char& s) { alloc.destroy(&s); });
        for(auto it = firstFree; it != firstElem; )
            alloc.destroy(--it);
        alloc.deallocate(firstElem, finalElem-firstElem);
    }
}

