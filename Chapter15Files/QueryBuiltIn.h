#ifndef QUERYBUILTIN
#define QUERYBUILTIN

#include <iostream>
#include <memory> //smart pointers
#include "textQuery.h"



class Query_Base{
    friend class Query;
protected:
    using lineNo = textQuery::lineNo;
    virtual ~Query_Base() { }
private:
    virtual queryResult eval(const textQuery& t) const = 0;
    virtual std::string rep() const = 0;
};






class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    Query(const Query&);
    Query(Query&&) noexcept;
    Query& operator=(const Query&);
    Query& operator=(Query&&) noexcept;
    ~Query();

    queryResult eval(const textQuery& t) const {return q->eval(t);}
    std::string rep() const { return q->rep(); }
private:
    Query(Query_Base* ptr): refCnt(new int(1)), q(ptr) { }

    int* refCnt;
    Query_Base* q;

};

Query operator~(const Query&);
Query operator&(const Query&, const Query&);
Query operator|(const Query&, const Query&);
std::ostream& operator<<(std::ostream&, const Query&);








class WordQuery : public Query_Base {
    friend class Query;
    WordQuery(const std::string& s): query_word(s) { }
    queryResult eval(const textQuery& t) const override { return t.query(query_word); }
    std::string rep() const override { return query_word;}
    std::string query_word;
};

class NotQuery : public Query_Base {
    friend Query operator~(const Query&);
    NotQuery(const Query& query): q(query) { }
    queryResult eval(const textQuery&) const override;
    std::string rep() const override { return "~(" + q.rep() + ")";}
    Query q;

};

class BinaryQuery : public Query_Base { //abstract base class since eval is not defined
protected:
    BinaryQuery(const Query& lhsQ, const Query& rhsQ, const std::string& op): lhs(lhsQ), rhs(rhsQ), opSym(op) { }
    std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
    Query lhs, rhs; //not made private as eval operator may need access to these
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "&") { }
    queryResult eval(const textQuery&) const override;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "|") { }
    queryResult eval(const textQuery&) const override;
};

#endif // QUERY
