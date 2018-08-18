#!/bin/sh

cc emitter.c error.c init.c lexer.c main.c parser.c symbol.c -o compiler

./compiler < test_success.txt