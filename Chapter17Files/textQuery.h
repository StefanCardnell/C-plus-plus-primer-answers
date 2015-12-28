#ifndef TEXTQUERY
#define TEXTQUERY

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <memory>
#include <tuple>

class textQuery{
public:
    using lineNo = std::vector<std::string>::size_type;
    using queryResult = std::tuple<std::string, std::shared_ptr<std::set<lineNo>>, std::shared_ptr<std::vector<std::string>>>;
    textQuery(std::ifstream&);
    queryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> lines;
    std::map<std::string, std::shared_ptr<std::set<lineNo>>> appearLines;

};

std::set<textQuery::lineNo>::iterator inline beginLine(const textQuery::queryResult& q) { return (std::get<1>(q))->begin();}
std::set<textQuery::lineNo>::iterator inline endLine(const textQuery::queryResult& q){ return (std::get<1>(q))->end();}
std::shared_ptr<std::vector<std::string>> inline get_file(const textQuery::queryResult& q) { return std::get<2>(q); }

std::ostream& print(std::ostream&, const textQuery::queryResult&);

#endif // TEXTQUERY
