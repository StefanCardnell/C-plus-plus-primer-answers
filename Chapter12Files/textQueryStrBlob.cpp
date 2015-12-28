#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "textQueryStrBlob.h"

using namespace std;

textQuery::textQuery(ifstream& input) {

    lineNo linenumber = 0;
    for(string s; getline(input, s); ++linenumber){
        istringstream tempProcess(s);
        for(string tempString; tempProcess >> tempString;){
            auto& sPtr = appearLines[tempString];
            if(!sPtr) sPtr = make_shared<set<lineNo>>();
            sPtr->insert(linenumber);
        }
        lines.push_back(s);
    }

}

queryResult textQuery::query(const string& s) const {

    static shared_ptr<set<lineNo>> nodata = make_shared<set<lineNo>>();

    auto found = appearLines.find(s);
    if(found != appearLines.end()) return queryResult(s, found->second, lines);
    else return queryResult(s, nodata, lines);
    /*previously I had nodata replaced with make_shared<set<lineNo>>(), the problem with this is that it allocates memory on the heap
    every time query is called, better to have a single static which allocates on the heap just once*/

}

ostream& print(ostream& os, const queryResult& r){

    os << r.word << " appears " << r.lineNumbers->size() << " time" << (r.lineNumbers->size() == 1 ? "" : "s") << endl;
    for(const auto& c : *(r.lineNumbers))
        os << "\t(line " << c+1 << ") " << strBlobPtrConst(r.lines, c).deref() << endl;

    return os;

}
