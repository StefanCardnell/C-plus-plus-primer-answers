#ifndef TEXTQUERYSTRVEC
#define TEXTQUERYSTRVEC

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <memory>
#include "strVec.h"

class queryResult;

class textQuery{

public:
    textQuery(std::ifstream&);
    queryResult query(const std::string&) const;
private:
    std::shared_ptr<strVec> lines;
    std::map<std::string, std::shared_ptr<std::set<size_t>>> appearLines;

};

class queryResult{
    friend std::ostream& print(std::ostream&, const queryResult&);
public:
    queryResult(std::string s, std::shared_ptr<std::set<size_t>> setPtr, std::shared_ptr<strVec> vecPtr):
        word(s), lineNumbers(setPtr), lines(vecPtr) { }
    std::set<size_t>::iterator begin() const { return lineNumbers->begin();}
    std::set<size_t>::iterator end() const { return lineNumbers->end();}
    std::shared_ptr<strVec> get_file() const { return lines; }
private:
    std::string word;
    std::shared_ptr<std::set<size_t>> lineNumbers;
    std::shared_ptr<strVec> lines;
};

std::ostream& print(std::ostream&, const queryResult&);



#endif // TEXTQUERY
