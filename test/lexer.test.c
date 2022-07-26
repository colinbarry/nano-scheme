#include <picotest.h>
#include <lexer.h>
#include <stdlib.h>
#include <string.h>

DEF_TEST(an_empty_string_has_no_tokens)
{
    struct Lexer *lex = lex_new("");
    ASSERT(lex_next(lex) == NULL);
    lex_delete(lex);
}

DEF_TEST(a_whitespace_only_string_has_no_tokens)
{
    struct Lexer *lex = lex_new("  \t  \r  \r\n   \n");
    ASSERT(lex_next(lex) == NULL);
    lex_delete(lex);
}

DEF_TEST(tokenizes)
{
    static char const *expected[] = {
        "(",
        "(",
        "the",
        "(",
        "cat",
        ")",
        ")",
        "sat",
        "on",
        ")",
        "#the-mat!",
        "!",
        NULL
    };

    struct Lexer *lex = lex_new("((the  (cat))sat    on   ) #the-mat! !");
    char const** p;

    for (p = expected; *p; ++p) {
        char *token = lex_next(lex);
        ASSERT(strcmp(token, *p) == 0);
        free(token);
    }
    ASSERT(lex_next(lex) == NULL);

    lex_delete(lex);
}

DEF_SUITE(lexer)
{
    RUN_TEST(an_empty_string_has_no_tokens);
    RUN_TEST(a_whitespace_only_string_has_no_tokens);
    RUN_TEST(tokenizes);
}

