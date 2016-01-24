#include <string>
#include "Sales_data.h"

class Token{
public:
    Token(): discrim(INT), ival(0) { }
    Token(const Token&);
    Token(Token&&);
    Token& operator=(const Token&);
    Token& operator=(Token&&);
    ~Token();

    Token& operator=(int);
    Token& operator=(char);
    Token& operator=(double);
    Token& operator=(const std::string&);
    Token& operator=(const Sales_data&);

private:

    enum {INT, CHR, DBL, STR, SDA} discrim;
    union{
        int ival;
        char cval;
        double dval;
        std::string sval;
        Sales_data sales;
    };

    void checkAndCopyUnion(const Token&); //You could make these two a single function using templates and std::forward if you were interested.
    void checkAndMoveUnion(Token&&);

};
