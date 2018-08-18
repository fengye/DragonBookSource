//
//  global.h
//  DragonBookProgram2
//

#ifndef global_h
#define global_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BSIZE   128
#define NONE    -1
#define EOS     '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define DONE    260

extern int tokenval;
extern int lineno;

typedef struct symentry {
    char*   lexptr;
    int     token;
} symentry;

extern symentry symtable[];

// Function declarations
extern void init(void);
extern void parse(void);
extern void error(const char* m);
extern void emit(int t, int tval);
// lexical analysis
extern int lexan(void);
// symbol table
extern int lookup(const char* s);
extern int insert(const char*s, int token);

#endif /* global_h */
