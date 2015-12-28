#ifndef QUERY
#define QUERY

#include <iostream>
#include <memory> //smart pointers
#include "textQuery.h"


class Query_Base{
protected:
    virtual ~Query_Base() { }

public:
    //virtual queryResult eval(const textQuery& t) const = 0;
    virtual std::string rep() const = 0;
};




class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    //queryResult eval(const textQuery& t) {return q->eval(t);}
    std::string rep() const { return q->rep(); }
    std::shared_ptr<Query_Base> getPtr() const { return q; }
private:
    Query(const std::shared_ptr<Query_Base>& ptr): q(ptr) { }
    std::shared_ptr<Query_Base> q;

};

Query operator~(const Query&);
Query operator&(const Query&, const Query&);
Query operator|(const Query&, const Query&);
std::ostream& operator<<(std::ostream&, const Query&);








class WordQuery : public Query_Base{
    friend class Query;
    WordQuery(const std::string& s): query_word(s) { }
    //queryResult eval(const textQuery& t) const override { return t.query(query_word); }
    std::string rep() const override { return query_word;}
    std::string query_word;
};

class NotQuery : public Query_Base {
    friend Query operator~(const Query&);
    NotQuery(const Query& query): q(query.getPtr()) { }
    //queryResult eval(const textQuery& t) const override;
    std::string rep() const override { return "~(" + q->rep() + ")";}
    std::shared_ptr<Query_Base> q;

};

class BinaryQuery : public Query_Base{
protected:
    BinaryQuery(const Query& lhsQ, const Query& rhsQ, const std::string& op): lhs(lhsQ.getPtr()), rhs(rhsQ.getPtr()), opSym(op) { }
    std::string rep() const override { return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")";}
    std::shared_ptr<Query_Base> lhs, rhs; //not made private as eval operator may need access to these
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "&") { }
    //queryResult eval(const textQuery& t) const override;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "|") { }
    //queryResult eval(const textQuery& t) const override;
};

#endif // QUERY
