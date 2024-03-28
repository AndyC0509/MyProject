#ifndef STOKENIZER_H
#define STOKENIZER_H
#include<string>
#include<iostream>
using namespace std;
#include "constants.h"
#include "token.h"

class STokenizer
{
public:
    STokenizer();
    STokenizer(char str[]);
    bool done();            //true: there are no more tokens
    bool more();            //true: there are more tokens
    //
    int token_type(char c);
    //int _pos;
    //---------------
    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t);
    //bool get_token(int& start_state, string& token);
    //set a new string as the input string
    void set_string(char str[]);

private:
    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table(int _table[][MAX_COLUMNS]);

    //extract the longest string that match
    //     one of the acceptable token types
    bool get_token(int& start_state, string& token);
    //---------------------------------
    char _buffer[MAX_BUFFER];       //input string buffer is a c string. it is a character array 
    int _pos;                       //current position in the string
    static int _table[MAX_ROWS][MAX_COLUMNS];
};

#endif