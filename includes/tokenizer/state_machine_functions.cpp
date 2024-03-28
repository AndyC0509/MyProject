
#include "stokenize.h"
#include "token.h"
#include "state_machine_functions.h"
#include "constants.h"
#include<string>
#include<iostream>
#include <iomanip>
using namespace std;

void init_table(int _table[MAX_ROWS][MAX_COLUMNS])
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLUMNS; j++)
        {
            _table[i][j] = -1;
        }
    }
    
}

void mark_success(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 1;
}

void mark_fail(int _table[MAX_ROWS][MAX_COLUMNS], int state)
{
    _table[state][0] = 0;
}

bool is_success(int _table[][MAX_COLUMNS], int state)
{
    if(_table[state][0] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mark_cells(int row, int _table[MAX_ROWS][MAX_COLUMNS], int from, int to, int state)
{
    for(int i = from; i < to; i++)
    {
        _table[row][i] = state;
    }
    //cout << "Row " << row <<" table a"<< _table[2]['a']<<endl;
}

void mark_cells(int row, int _table[MAX_ROWS][MAX_COLUMNS], const char columns[], int state)
{
    for(int i = 0; columns[i] != '\0'; i++)
    {
        int num = static_cast<unsigned char>(columns[i]);
        _table[row][num] = state; 
    }
    //cout << "Row " << row << " charater " << columns << " state " << state << " table 1 = "<< _table[7]['1']<<endl;
}

void mark_cell(int row, int table[MAX_ROWS][MAX_COLUMNS], int column, int state)
{
    table[row][column] = state;
    //cout << "Row " << row << " charater " << column << " state " << state << " table 4 = "<< table[6]['.']<<endl;
}

void print_table(int _table[][MAX_COLUMNS]) 
{
    
}

void show_string(char s[], int _pos)
{
    for(int i = 0; s[i] !='\0'; i++)
    {
        cout << s[i];
    }
    cout << " pos: ";
    cin >> _pos;
    
    cout <<endl<< setw(_pos) << "^"<<endl;
}
