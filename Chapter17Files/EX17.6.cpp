//#define NDEBUG
#include <iostream>
#include <fstream> //IO file stream
#include <sstream> //stringstream
#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
#include <cstring> //c-style string functions
#include <cstddef> //for size_t type and ptr_diff type
#include <cctype> //for chararacter related functions
#include <stdexcept> //Plain/Runtime/Logic exception classes
#include <initializer_list> //for initializer_list type
#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
#include <cassert> //assert preprocessor macro
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <stack> //sequential container adaptor
#include <queue> //sequential container adaptor, includes priority_queue
#include <algorithm>
#include <numeric> //more container algorithms
#include <functional> //for bind library function (and ref/cref), and library defined function objects
#include <map> //for map and multimap associative containers
#include <set> //for set and multiset associative containers
#include <unordered_map> //for unordered_map and unordered_multimap
#include <unordered_set> //for unordered_set and unordered_multiset
#include <utility> //for pair library type (used in map associative container), also for std::move and std::forward
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class
#include <type_traits> //type transformation templates
#include <tuple> //tuple class
//
//
////difference_type (iterator arithmetic) and ::size_type are for strings/vectors
////ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)
//
////-c is for separate compilation (creates .o object files)
////-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
////-std=c++11 for C++11 support

using namespace std;

#include "Sales_data.h"


struct matches{
    vector<vector<Sales_data>>::difference_type storeNo;
    vector<Sales_data>::const_iterator firstSale;
    vector<Sales_data>::const_iterator finalSale;
};

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs){
    return lhs.isbn() < rhs.isbn();
}

vector<matches> findStores(const vector<vector<Sales_data>>& stores, const string& book){
    vector<matches> ret;
    for(auto it = stores.cbegin(); it != stores.cend(); ++it){
        auto iterPair = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if(iterPair.first != iterPair.second)
            ret.push_back(matches{it-stores.cbegin(), iterPair.first, iterPair.second});
    }
    return ret;
}

ostream& processBooks(istream& is, ostream& os, const vector<vector<Sales_data>>& allSales){
    string book;
    while(is >> book){
        vector<matches> Stores = findStores(allSales, book);
        if(Stores.empty()){
            os << book << " did not sell in any store." << endl;
            continue;
        }
        for(const auto& store : Stores)
            os << "Store: " << store.storeNo << " ... Sold: " << accumulate(store.firstSale, store.finalSale, Sales_data(book)) << endl;
    }
    return os;
}


int main(){

    vector<vector<Sales_data>> x = {
        {{"test", 2, 3}, {"test", 2, 3}, {"vvvvv", 2, 3}, {"zzzzzzz", 2, 3}},
        {{"test", 2, 3}, {"vvvvv", 2, 3}, {"zzzz", 2, 3}, {"zzzz", 2, 3}},
        {{"aaaa", 2, 3}, {"zzzzz", 2, 3}, {"zzzzz", 2, 3}, {"zzzzz", 2, 3}},
        {{"bbbb", 2, 3}, {"bbbb", 2, 3}, {"gggg", 2, 3}, {"test", 2, 3}},
        {{"aaaa", 2, 3}, {"aaaa", 2, 3}, {"test", 2, 3}, {"test", 2, 3}},
    };

    processBooks(cin, cout, x);

}














