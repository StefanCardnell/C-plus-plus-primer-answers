#include <string>
#include "Token.h"

using std::string; //needed to call string destructor explicitly

Token::Token(const Token& t) {

    checkAndCopyUnion(t);
    discrim = t.discrim;

}

Token::Token(Token&& t){

    checkAndMoveUnion(std::move(t));
    discrim = std::move(t.discrim);

}

Token& Token::operator=(const Token& t) {

    if(discrim == STR && t.discrim != STR) sval.~string();
    else if(discrim == SDA && t.discrim != SDA) sales.~Sales_data();

    if(discrim == STR && t.discrim == STR) sval = t.sval;
    else if(discrim == SDA && t.discrim == SDA) sales = t.sales;
    else checkAndCopyUnion(t);

    discrim = t.discrim;
    return *this;

}

Token& Token::operator=(Token&& t){

    if(this != &t){
        if(discrim == STR && t.discrim != STR) sval.~string();
        else if(discrim == SDA && t.discrim != SDA) sales.~Sales_data();

        if(discrim == STR && t.discrim == STR) sval = std::move(t.sval);
        else if(discrim == SDA && t.discrim == SDA) sales = std::move(t.sales);
        else checkAndMoveUnion(std::move(t));

        discrim = std::move(t.discrim);
    }
    return *this;


}

Token::~Token() {
    if(discrim == STR) sval.~string();
    else if(discrim == SDA) sales.~Sales_data();
}

Token& Token::operator=(int i){
    if(discrim == STR) sval.~string();
    else if(discrim == SDA) sales.~Sales_data();
    ival = i;
    discrim = INT;
    return *this;
}

Token& Token::operator=(char c){
    if(discrim == STR) sval.~string();
    else if(discrim == SDA) sales.~Sales_data();
    cval = c;
    discrim = CHR;
    return *this;
}

Token& Token::operator=(double d){
    if(discrim == STR) sval.~string();
    else if(discrim == SDA) sales.~Sales_data();
    dval = d;
    discrim = DBL;
    return *this;
}

Token& Token::operator=(const std::string& s){
    if(discrim == STR) sval = s;
    else{
        if(discrim == SDA) sales.~Sales_data();
        new (&sval) string(s);
    }
    discrim = STR;
    return *this;
}

Token& Token::operator=(const Sales_data& s){
    if(discrim == SDA) sales = s;
    else{
        if(discrim == STR) sval.~string();
        new (&sales) Sales_data(s);
    }
    discrim = SDA;
    return *this;
}

void Token::checkAndCopyUnion(const Token& t){

    switch(t.discrim){
        case INT: ival = t.ival; break;
        case CHR: cval = t.cval; break;
        case DBL: dval = t.dval; break;
        case STR: new (&sval) std::string(t.sval); break;
        case SDA: new (&sales) Sales_data(t.sales); break;
    }

}

void Token::checkAndMoveUnion(Token&& t){

    switch(t.discrim){
        case INT: ival = t.ival; break;
        case CHR: cval = t.cval; break;
        case DBL: dval = t.dval; break;
        case STR: new (&sval) std::string(std::move(t.sval)); break;
        case SDA: new (&sales) Sales_data(std::move(t.sales)); break;
    }

}
