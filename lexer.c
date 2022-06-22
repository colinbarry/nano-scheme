#include "lexer.h"
#include <stdlib.h>
#include <string.h>

#define WHITESPACE " \n\t\r\a"
#define TERMINATOR WHITESPACE "()"

struct Lexer {
    char const* read;
};

struct Lexer* lex_new(char const *str)
{
    struct Lexer *lexer = malloc(sizeof(*lexer));
    lexer->read = str;
    return lexer;
}

char *lex_next(struct Lexer *lexer)
{
    /** Tokens can be either:
     * open or close parens
     * a run of any characters apart from white space or parens
     */
    char const *tokenbegin;
    char *token;
    size_t tokenlen;

    lexer->read += strspn(lexer->read, WHITESPACE);
    if (!*lexer->read) {
        return NULL;
    } 

    tokenbegin = lexer->read;

    if (*lexer->read == '(' || *lexer->read == ')') {
        ++lexer->read;
    } else {
        char const *terminator = strpbrk(lexer->read, TERMINATOR);
        if (terminator) {
            lexer->read = terminator;
        } else {
            lexer->read += strlen(lexer->read);
        }
    }

    tokenlen = lexer->read - tokenbegin;

    token = malloc(tokenlen + 1);
    memcpy(token, tokenbegin, tokenlen);
    token[tokenlen] = '\0';

    return token;
}

void lex_delete(struct Lexer *lexer)
{
    free(lexer);
}

