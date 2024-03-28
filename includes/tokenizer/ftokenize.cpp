#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "token.h"
#include "stokenize.h"
#include "state_machine_functions.h"
#include "constants.h"
#include "ftokenize.h"

FTokenizer::FTokenizer(const char* fname) : _pos(0), _blockPos(0)
{
    //STokenizer s;
    _f.open(fname);
    if(_f.fail())
    {
        cout << "Fail not open"<<endl;
        _more = false;
    }
    else
    {
        _more = true;
        get_new_block();
        
    }
    //_f.close();
}

Token FTokenizer::next_token()
{
    Token t;
    if(_stk.more())
    {
        _stk >> t;
        //return Token();
    }
    
    if(!_stk.more() && more())
    {
        get_new_block();
    
    //_pos =strlen(t.token_str().c_str());
    //cout << "_blocPos(1) : ----->" <<block_pos()<< endl;
    //cout << "My _pos(next token)1: " << _pos << endl;

    _stk >> t;

    //cout << "My _pos(next token)2: " << _pos << endl;
    //cout << "_blocPos(2) : ----->" <<block_pos()<< endl;

    int t_pos = 0;

    // if (t.type_string()=="ALPHA" )
    // {
    
    t_pos = strlen(t.token_str().c_str());

    // }
    // else
    // {
    //     t_pos = 0;
    // }
    t_pos = t.token_str().length();
    //cout << "t_pos : ----->" <<t_pos<< endl;

    _pos += t_pos;
    
    cout << "My _pos(next token)3: " << _pos << endl;
    //cout << "_blocPos(2) : ----->" <<block_pos()<< endl;
    //cout << "_f.gcount(): ------>"<<_f.gcount()<<endl;
    }

    if(_pos >= _blockPos)
    {
        cout << "cut off!!!!" << endl; 
        //cout << "My _pos(next token)3: " << _pos << endl;
        //cout << "_blocPos(2) : ----->" <<block_pos()<< endl;
        //cout << "_f.gcount(): ------>"<<_f.gcount()<<endl;
        _pos = 0;
        //cout << "----- New Block ---------------------"<<"[" << _blockPos<<"] bytes"<<endl;
        _blockPos = 0;
        //get_new_block();
        
    }

    return t;
}

bool FTokenizer::more()
{
    // if(_blockPos <= _pos)
    // {
    //     _more = true;
    // }
    // else
    // {
    //     _more = false;
    // }
    return _more;
    
}

int FTokenizer::pos()
{
    return _pos;
}

int FTokenizer::block_pos()
{
    return _blockPos;
}

FTokenizer& operator >> (FTokenizer& f, Token& t)
{
    
    //f._pos =strlen(t.token_str().c_str());

    // t = f.next_token();
    
    t = f.next_token();
    // f._pos =strlen(t.token_str().c_str());
    return f;
}

bool FTokenizer::get_new_block()
{
    if(_f.eof())
    {
        _more = false;
        return false;
    }
    char block[MAX_BLOCK+1];
    //int Total_text = 0;
    //Total_text += MAX_BLOCK;
    _f.read(block, MAX_BLOCK+1); 
    if (_f.gcount() == 0)
    {
        _more = false;
        return false;
    }

    //cout << "_f.gcount > 0"<<endl;
    block[_f.gcount()] = '\0' ;
    _stk.set_string(block); //put to stk
    //cout << "_blocPos(0) : ----->" << endl;
    _blockPos = _f.gcount()-1;
    cout << "----- New Block ---------------------"<<"[" << _blockPos<<"] bytes"<<endl<<endl;
   
    _more = true;
    //cout << "My _pos(get_new): " << _pos << endl;
   
    return true;
}
