#ifndef QUERY
#define QUERY

#include <iostream>
#include <memory> //smart pointers
#include "textQuery.h"

namespace chapter15{

    class Query_Base{
        friend class Query;
    protected:
        using lineNo = chapter12::textQuery::lineNo;
        virtual ~Query_Base() { }
        /*Implicit noexcept for destructor should be true anyway since we have no members*/
    private:
        virtual chapter12::queryResult eval(const chapter12::textQuery& t) const = 0;
        virtual std::string rep() const = 0;
    };






    class Query{
        friend Query operator~(const Query&);
        friend Query operator&(const Query&, const Query&);
        friend Query operator|(const Query&, const Query&);
    public:
        /*This string constructor should definitely not be noexcept since it allocates on the heap*/
        Query(const std::string&);
        chapter12::queryResult eval(const chapter12::textQuery& t) const {return q->eval(t);}
        std::string rep() const { return q->rep(); }
    private:
        /*looking up, the shared_ptr copy constructor is noexcept so this constructor can be too*/
        Query(const std::shared_ptr<Query_Base>& ptr) noexcept: q(ptr) { }
        std::shared_ptr<Query_Base> q;

    };

    Query operator~(const Query&);
    Query operator&(const Query&, const Query&);
    Query operator|(const Query&, const Query&);
    std::ostream& operator<<(std::ostream&, const Query&);








    class WordQuery : public Query_Base {
        friend class Query;
        /*Not listed noexcept since it copies a string*/
        WordQuery(const std::string& s): query_word(s) { }
        chapter12::queryResult eval(const chapter12::textQuery& t) const override { return t.query(query_word); }
        std::string rep() const override { return query_word;}
        std::string query_word;
    };

    class NotQuery : public Query_Base {
        friend Query operator~(const Query&);
        /*This is noexcept if Query copy constructor cannot throw, we can check this condition ourselves (it should be true)*/
        /*declval<T> has a return type of T&& (cannot be called but noexcept does not evaluate its expression anyway)*/
        NotQuery(const Query& query) noexcept(noexcept(Query(std::declval<Query&>()))) : q(query) { }
        chapter12::queryResult eval(const chapter12::textQuery&) const override;
        std::string rep() const override { return "~(" + q.rep() + ")";}
        Query q;

    };

    class BinaryQuery : public Query_Base { //abstract base class since eval is not defined
    protected:
        /*Copies a string, cannot be declared noexcept */
        BinaryQuery(const Query& lhsQ, const Query& rhsQ, const std::string& op): lhs(lhsQ), rhs(rhsQ), opSym(op) { }
        std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
        Query lhs, rhs; //not made private as eval operator may need access to these
        std::string opSym;
    };

    class AndQuery : public BinaryQuery {
        friend Query operator&(const Query&, const Query&);
        /*Since the binary query constructor is not noexcept neither is this*/
        AndQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "&") { }
        chapter12::queryResult eval(const chapter12::textQuery&) const override;
    };

    class OrQuery : public BinaryQuery {
        friend Query operator|(const Query&, const Query&);
        /*Since the binary query constructor is not noexcept neither is this*/
        OrQuery(const Query& lhs, const Query& rhs): BinaryQuery(lhs, rhs, "|") { }
        chapter12::queryResult eval(const chapter12::textQuery&) const override;
    };

}

#endif // QUERY
