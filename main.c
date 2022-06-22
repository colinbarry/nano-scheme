#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct Lexer* lexer;
    char *token;

    lexer = lex_new("(find 'foo ((france paris)( germany berlin )  )  :key #'cadr");
    
    for (token = lex_next(lexer); token; token = lex_next(lexer)) {
        printf("`%s`\n", token);
        free(token);
    }
    puts("#OK");

    lex_delete(lexer);

    return EXIT_SUCCESS;
}

