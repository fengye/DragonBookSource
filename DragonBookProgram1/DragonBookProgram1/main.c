//
//  main.c
//  DragonBookProgram1
//
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static int lookahead;

void error() {
    printf("Syntax error\n");
    exit(1);
}

void match(int t) {
    if (lookahead == t)
        lookahead = getchar();
    else
        error();
}

void term() {
    if (isdigit(lookahead)) {
        putchar(lookahead);
        match(lookahead);
    }
    else
        error();
}

void expr() {
    term();
    while(1) {
        if (lookahead == '+') {
            match('+'); term(); putchar('+');
        }
        else if (lookahead == '-' ) {
            match('-'); term(); putchar('-');
        }
        else
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    lookahead = getchar();
    expr();
    putchar('\n');
}
