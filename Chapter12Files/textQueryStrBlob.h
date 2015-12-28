#ifndef TEXTQUERY
#define TEXTQUERY

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <memory>
#include "StrBlob.h"

class queryResult;

class textQuery{

public:
    using lineNo = std::vector<std::string>::size_type;
    textQuery(std::ifstream&);
    queryResult query(const std::string&) const;
private:
    strBlob lines;
    std::map<std::string, std::shared_ptr<std::set<lineNo>>> appearLines;

};

class queryResult{
    friend std::ostream& print(std::ostream&, const queryResult&);
public:
    using lineNo = std::vector<std::string>::size_type;
    queryResult(std::string s, std::shared_ptr<std::set<lineNo>> setPtr, strBlob vecPtr):
        word(s), lineNumbers(setPtr), lines(vecPtr) { }
private:
    std::string word;
    std::shared_ptr<std::set<lineNo>> lineNumbers;
    strBlob lines;

};

std::ostream& print(std::ostream&, const queryResult&);



#endif // TEXTQUERY
