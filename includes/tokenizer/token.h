#ifndef TOKEN_H
#define TOKEN_H
#include<string>
#include<iostream>
using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type); // type is returning the number of the character
    friend ostream& operator <<(ostream& outs, const Token& t);
    int type() const;
    string type_string() const;
    string token_str() const;
private:
    string _token;
    int _type;
};
#endif