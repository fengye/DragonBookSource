//
//  init.c
//  DragonBookProgram2
//
#include "global.h"
symentry keywords[] = {
    "div", DIV,
    "mod", MOD,
    0, 0
};

void init()
{
    symentry* p;
    for(p = keywords; p->token; p++)
    {
        insert(p->lexptr, p->token);
    }
}
