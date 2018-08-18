//
//  lexer.c
//  DragonBookProgram2
//
#include "global.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan() {
    int t;
    while(1) {
        t = getchar();
        if (t == ' ' || t == '\t')
            ;
        else if (t == '\n')
            lineno++;
        else if (isdigit(t))
        {
            ungetc(t, stdin);
            scanf("%d", &tokenval);
            return NUM;
        }
        else if (isalpha(t))
        {
            int buf_index = 0;
            while(isalnum(t))
            {
                lexbuf[buf_index] = t;
                t = getchar();
                buf_index++;
                if (buf_index >= BSIZE)
                    error("compiler error");
            }
            lexbuf[buf_index] = EOS;
            if (t != EOF)
            {
                ungetc(t, stdin);
            }
            
            int ptr = lookup(lexbuf);
            if (ptr == 0)
            {
                ptr = insert(lexbuf, ID); // insert new identifier to symbol table
            }
            tokenval = ptr;
            return symtable[ptr].token;
        }
        else if (t == EOF)
            return DONE;
        else {
            tokenval = NONE;
            return t;
        }
    }
}
