//
//  parser.c
//  DragonBookProgram2
//
#include "global.h"

int lookahead;

void expr(void);

void match(int t)
{
    if (lookahead == t)
        lookahead = lexan();
    else
        error("syntax error");
}

void factor()
{
    switch(lookahead)
    {
        case '(':
        {
            match('('); expr(); match(')');
            break;
        }
        case NUM:
        {
            emit(NUM, tokenval); match(NUM);
            break;
        }
        case ID:
        {
            emit(ID, tokenval); match(ID);
            break;
        }
        default:
            error("syntax error");
    }
}

void term()
{
    int saved_token;
    factor();
    while(1)
    {
        switch(lookahead)
        {
            case '*':
            case '/':
            case DIV:
            case MOD:
            {
                saved_token = lookahead;
                match(lookahead); factor(); emit(saved_token, NONE);
                continue;
            }
            default:
                return;
        }
    }
}

void expr()
{
    int saved_token;
    term();
    while(1)
    {
        switch(lookahead)
        {
            case '+':
            case '-':
                saved_token = lookahead;
                match(lookahead); term(); emit(saved_token, NONE);
                continue;
            default:
                return;
        }
    }
}

void parse()
{
    lookahead = lexan();
    while(lookahead != DONE)
    {
        expr(); match(';');
    }
}


