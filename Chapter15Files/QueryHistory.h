#ifndef QUERYHISTORY
#define QUERYHISTORY

#include <vector>
#include "Query.h"

class QueryHistory{
public:
    Query& operator[](std::vector<Query>::size_type n) { return *(history[n]); }
    const Query& operator[](std::vector<Query>::size_type n) const { return *(history[n]); }

    size_t add(const Query& q) { history.push_back(std::make_shared<Query>(q)); return history.size()-1; }
    size_t add(Query&& q) { history.push_back(std::make_shared<Query>(std::move(q))); return history.size()-1; }

private:
    std::vector<shared_ptr<Query>> history;

    /*Presumably the user wants to be able to add temporaries. As a result we must COPY/MOVE whatever is supplied to QueryHistory.
    In which case why not use straight Query objects? (i.e. vector<Query>?) Because then copied QueryHistory objects refer
    to separate objects. So use a pointer as the element type, and copy/move the supplied queries in to dynamic memory.
    To handle dynamic memory, use a shared_ptr instead */

};

#endif // QUERYHISTROY
