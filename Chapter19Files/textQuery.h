#ifndef TEXTQUERY
#define TEXTQUERY

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <memory>

class textQuery{
public:
    using lineNo = std::vector<std::string>::size_type;
    class queryResult;
    textQuery(std::ifstream&);
    queryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> lines;
    std::map<std::string, std::shared_ptr<std::set<lineNo>>> appearLines;

};

class textQuery::queryResult{
    friend std::ostream& print(std::ostream&, const queryResult&);
    friend std::ostream& print(std::ostream&, const queryResult&, unsigned, unsigned);
public:
    queryResult(std::string s, std::shared_ptr<std::set<lineNo>> setPtr, std::shared_ptr<std::vector<std::string>> vecPtr):
        word(s), lineNumbers(setPtr), lines(vecPtr) { }
    std::set<lineNo>::iterator begin() const { return lineNumbers->begin();}
    std::set<lineNo>::iterator end() const { return lineNumbers->end();}
    std::shared_ptr<std::vector<std::string>> get_file() const { return lines; }
private:
    std::string word;
    std::shared_ptr<std::set<lineNo>> lineNumbers;
    std::shared_ptr<std::vector<std::string>> lines;
};

std::ostream& print(std::ostream&, const textQuery::queryResult&);
std::ostream& print(std::ostream&, const textQuery::queryResult&, unsigned, unsigned);



#endif // TEXTQUERY
