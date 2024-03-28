
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "token.h"
#include "stokenize.h"
#include "state_machine_functions.h"
#include "constants.h"

Token::Token() : _token(""), _type(0){}
Token :: Token(string str, int type) : _token(str) , _type(type){}
ostream& operator <<(ostream& outs, const Token& t)
{
    //cout << "check operator << Token: ";
    outs <<"|" << t._token <<"|";
    return outs;
}

int Token::type() const
{
    return _type;
}
string Token::type_string() const
{
    switch(_type)
    {
        case TOKEN_NUMBER:
            return "NUMBER";
        case TOKEN_ALPHA:
            return "ALPHA";
        case TOKEN_SPACE:
            return "SPACE";
        case TOKEN_OPERATOR:
            return "OPERATOR";
        case TOKEN_PUNC:
            return "PUNC";
        case TOKEN_UNKNOWN:
            return "UNKNOWN";
        case TOKEN_END:
            return "END";
        default:
            return "NOTFOUND";
    }

}
string Token::token_str() const
{
    return _token;
}