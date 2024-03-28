#include "stokenize.h"
#include "token.h"
#include "state_machine_functions.h"
#include "constants.h"
#include "ftokenize.h"
#include <iomanip>
#include <cctype>
#include <string>
#include <cstring>
int STokenizer :: _table[MAX_ROWS][MAX_COLUMNS] = {0};
STokenizer :: STokenizer () : _pos(0)
{
    //_buffer[0] = '\0';
    make_table(_table);
}

STokenizer :: STokenizer (char str[]) : _pos(0)
{
    set_string(str);
    make_table(_table);

}


bool STokenizer :: get_token(int& start_state, string& token)
{
    // if(_pos > strlen(_buffer)) 
    // {
    //     cout << "called this '0'"<<endl<<endl;
    //     _pos = strlen(_buffer);
    //     return false;
    // }
    
    token.clear(); 
    int state = start_state;
    string curr_t;
    int last_pos = -1;
    int last_state = start_state;
    string temp_c;
    bool check = false;
    char curr_c;
    int pointing_state;
    
    //cout << "Last_pos(start): ->>>> " << last_pos <<endl<<endl;
    //cout << "last_state(start): ->>>> " << last_state <<endl<<endl;
    //cout << "_pos: (start)" << _pos<< endl;
    //cout << "strlen(_buffer): "<<strlen(_buffer) << endl;
    if(_pos > strlen(_buffer)) 
    {
        _pos = strlen(_buffer);
        return false;
    }
    while(_pos < strlen(_buffer))
    {
        
        curr_c = _buffer[_pos];
        pointing_state = _table[state][curr_c];
        //cout << "is success: --->>>>" << is_success(_table, pointing_state) << endl <<endl;
        if(is_success(_table, pointing_state))
        {
            last_pos = _pos;
            last_state = pointing_state;
        }
        //cout << curr_c << endl;
        //cout << "Last_pos(1): ->>>> " << last_pos <<endl<<endl;
        // cout << "last_state(1): ->>>> " << last_state <<endl<<endl;
        //cout << "curr_t: " << curr_t <<endl<<endl;
        //cout << "char(1): " << curr_c << endl<<endl;
        if(pointing_state != -1)
        {
            if(is_success(_table, pointing_state) && curr_c != '\0')
            {
                if(check)
                {
                    curr_t += temp_c + curr_c;
                    check = false;
                }
                else
                {
                    curr_t += curr_c;
                }
                
                state = pointing_state;
                _pos++;
            }
            if(!is_success(_table, pointing_state)&& curr_c != '\0')
            {
                temp_c = curr_c;
                state = pointing_state;
                _pos++;
                check = true;
            }
        }
        else
        {
            token = curr_t;
            start_state = state;
            return true;
        }
        // cout << endl;
        //cout << "_pos(2) : " << _pos<< endl<<endl;
        //cout << "char: " << curr_c << endl<<endl;
        //cout << "curr_t(2): " << curr_t <<endl<<endl;
        //cout << "next_state from table: " << pointing_state << endl<<endl;
        //cout << "Last_pos(2): ->>>> " << last_pos <<endl<<endl;
        //cout << "last_state(2): ->>>> " << last_state <<endl<<endl;
    }
    //cout << "check step" << endl <<endl;
    if(_buffer[_pos] == '\0' )
    {
        //works
        // _pos = last_pos;
        // start_state = last_state;
        // token = _buffer[_pos];
        // _pos++;
        // return true;
        //not work
        if(is_success(_table, pointing_state) && !curr_t.empty())
        {
            token = curr_t;
            //cout << "check . call success!!!!!!"<<endl<<endl;
            return true;
        }
        // else
        // {
            _pos = last_pos;
            start_state = last_state;
            token = _buffer[_pos];
            _pos++;
            //cout << "check 2 call success!!!!!!!" << endl << endl;
            return true;
        //}
    }
    return false;
}

STokenizer& operator >> (STokenizer& s, Token& t)
{
    string tok;
    int start_state = 0;
    if(s._buffer[s._pos] == '\0')
    {
        //cout << "Nothing" << endl << endl;
        s._pos = MAX_BUFFER+1;
        return s;
    }
    else
    {
        if(s.get_token(start_state, tok))
        {
            int t_type = 0;
            if (!tok.empty()) 
            {
                char firstChar = tok[0];
                if (isdigit(firstChar)) 
                {
                    t_type = TOKEN_NUMBER;
                } 
                else if (isalpha(firstChar)) 
                {
                    t_type = TOKEN_ALPHA;
                } 
                else if (ispunct(firstChar)) 
                {
                    t_type = TOKEN_PUNC;
                } 
                else if (isspace(firstChar)) 
                {
                    t_type = TOKEN_SPACE;
                }
                else
                {
                    t_type = TOKEN_UNKNOWN;
                }
            }
            
            t = Token(tok, t_type);
            //cout << ">> called success"<< endl<<endl;
        }
        else
        {
            
            t = Token("", TOKEN_UNKNOWN); //no more token
            //cout << ">> called failed"<< endl<<endl;
        }
    }   
    // if (s._pos <= strlen(s._buffer))
    // {
    //     cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;
    // }
    return s;
}

void STokenizer :: make_table(int _table[][MAX_COLUMNS])
{
    //doubles:
    init_table(_table);
    
    mark_cells(0, _table, DIGITS, 1);
    mark_cells(0, _table, ALFA, 2);

    mark_cell(0, _table, ' ', TOKEN_SPACE);
    mark_cell(0, _table, '\t', TOKEN_SPACE);
    mark_cell(0, _table, '\n', TOKEN_SPACE);
    
    mark_cells(0, _table, OPERATORS, TOKEN_OPERATOR);
    mark_cells(0, _table, PUNC, TOKEN_PUNC);

    //mark_cell(0, _table, '\0', TOKEN_UNKNOWN);
    mark_cells(1, _table, DIGITS, TOKEN_NUMBER);
    mark_cells(2, _table, ALFA, TOKEN_ALPHA);
    mark_cell(3, _table, ' ', TOKEN_SPACE);
    mark_cell(3, _table, '\t', TOKEN_SPACE);
    mark_cell(3, _table, '\n', TOKEN_SPACE);
    
    mark_cells(4, _table, OPERATORS, TOKEN_OPERATOR);
    mark_cells(5, _table, PUNC, TOKEN_PUNC);
    mark_cell(1, _table, '.', 6);
    mark_cells(6, _table, DIGITS, 7);
    mark_cells(7, _table, DIGITS, 7);


    mark_success(_table, TOKEN_NUMBER);
    mark_success(_table, TOKEN_ALPHA);
    mark_success(_table, TOKEN_SPACE);
    mark_success(_table, TOKEN_OPERATOR);
    mark_success(_table, TOKEN_PUNC);
    mark_fail(_table, 6);
    mark_success(_table, 7);
}

bool STokenizer :: done()
{
    if(_pos > strlen(_buffer))
    {
        return true;
    }
    return false;
}

bool STokenizer :: more()
{
    if(_pos <= strlen(_buffer)+1)
    {
        return true;
    }
    return false;
}

void STokenizer::set_string(char str[])
{
    strcpy(_buffer, str);
    _buffer[strlen(str) + 1] = '\0';
    _pos = 0;
}


