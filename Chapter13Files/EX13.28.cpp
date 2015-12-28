//#define NDEBUG
#include <iostream>
//#include <fstream> //IO file stream
//#include <sstream> //stringstream
//#include <iterator> //begin/end functions for arrays
#include <string>
#include <vector>
//#include <cstring> //c-style string functions
//#include <cstddef> //for size_t type and ptr_diff type
//#include <cctype> //for chararacter related functions
//#include <stdexcept> //Plain/Runtime/Logic exception classes
//#include <initializer_list> //for initializer_list type
//#include <cstdlib> //for preprocessor variables like NULL, EXIT_SUCCESS and EXIT_FAILURE
//#include <cassert> //assert preprocessor macro
//#include <array>
//#include <list>
//#include <deque>
//#include <forward_list>
//#include <stack> //sequential container adaptor
//#include <queue> //sequential container adaptor, includes priority_queue
//#include <algorithm>
//#include <numeric> //more container algorithms
//#include <functional> //for bind library function (and ref/cref)
//#include <map> //for map and multimap associative containers
//#include <set> //for set and multiset associative containers
//#include <unordered_map> //for unordered_map and unordered_multimap
//#include <unordered_set> //for unordered_set and unordered_multiset
//#include <utility> //for pair library type (used in map associative container
#include <memory> //for dynamic memory smart pointers
#include <new> //nothrow and bad_alloc types, and allocator class

//difference_type (iterator arithmetic) and ::size_type are for strings/vectors
//ptrdiff_t (pointer arithmetic) and size_t are for built-in arrays (inside cstddef headers!)

//-c is for separate compilation (creates .o object files)
//-D is to define preprocessor variables at the top of files (e.g. -D NDEBUG)
//-std=c++11 for C++11 support


using namespace std;

class TreeNode {
public:
    TreeNode(): count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode& rhs): value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode& operator=(const TreeNode& rhs);
    ~TreeNode();
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};


TreeNode& TreeNode::operator=(const TreeNode& rhs){

    ++*rhs.count;
    if(--*count == 0){
        delete left;
        delete right;
        delete count;
    }
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    value = rhs.value;
    return *this;

}

TreeNode::~TreeNode() {

    if(--*count == 0){
        delete left;
        delete right;
        delete count;
    }

}

class BinStrTree {
public:
    BinStrTree(): root(new TreeNode()) { }
    BinStrTree(const BinStrTree& rhs): root(new TreeNode(*rhs.root)) { }
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree() { delete root;}

private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs){
    TreeNode* temp = new TreeNode(*rhs.root);
    delete root;
    root = temp;
    return *this;
}

int main(){




}








