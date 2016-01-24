#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm> //for removePunc
#include <iostream>
#include "textQuery.h"

using namespace std;

std::string& removePunc(string& s){
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    return s;
}

textQuery::textQuery(ifstream& input): lines(make_shared<vector<string>>()) {

    lineNo linenumber = 0;
    for(string s; getline(input, s); ++linenumber){
        istringstream tempProcess(s);
        for(string tempString; tempProcess >> tempString;){
            auto& sPtr = appearLines[removePunc(tempString)];
            if(!sPtr) sPtr = make_shared<set<lineNo>>();
            sPtr->insert(linenumber);
        }
        lines->push_back(s);
    }

}

textQuery::queryResult textQuery::query(const string& s) const {

    static shared_ptr<set<lineNo>> nodata = make_shared<set<lineNo>>();

    auto found = appearLines.find(s);
    if(found != appearLines.end()) return queryResult(s, found->second, lines);
    else return queryResult(s, nodata, lines);
    /*previously I had nodata replaced with make_shared<set<lineNo>>(), the problem with this is that it allocates memory on the heap
    every time query is called, better to have a single static which allocates on the heap just once*/

}

ostream& print(ostream& os, const textQuery::queryResult& r){

    os << r.word << " appears " << r.lineNumbers->size() << " time" << (r.lineNumbers->size() == 1 ? ":" : "s:") << endl;
    for(const auto& c : *(r.lineNumbers))
        os << "\t(line " << c+1 << ") " << (*r.lines)[c] << endl;

    return os;

}

ostream& print(ostream& os, const textQuery::queryResult& r, unsigned lower, unsigned upper){

    if(lower > upper){
        os << "Invalid lower and upper bound for print function!" << endl;
        return os;
    }

    auto begin = r.lineNumbers->lower_bound(lower-1);
    auto end = r.lineNumbers->upper_bound(upper-1);

    auto sz = distance(begin, end);

    os << r.word << " appears " << sz << " time" << (sz == 1 ? "" : "s") << " in the range of lines "
       << "[" << lower << "," << upper << "]:" << endl;

    for(auto it = begin; it != end; ++it)
        os << "\t(line " << (*it)+1 << ") " << (*r.lines)[*it] << endl;

    return os;

}
