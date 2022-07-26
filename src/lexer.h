#ifndef LEXER_H_
#define LEXER_H_

struct Lexer;

/** Creates a new lexer for the gtiven source string.
 *
 * @param source    Text to be tokenized. This is stored as a view over the
 *                  original string, and so the original string must not be 
 *                  deleted or updated before calling `lex_delete`
 * @return          A new lexer.
 */
struct Lexer* lex_new(char const *source);

/** Returns the next token, or NULL if there are not more tokens. 
 *
 * @param lexer     The lexer
 * @return          A token, or NULL if there are no more tokens. The caller
 *                  takes ownership of this token and must free if.
 */
char *lex_next(struct Lexer *lexer);

/** Destructs a `Lexer`
 *
 * @param lexer     A `Lexer` to be destroyed.
 */
void lex_delete(struct Lexer *lexer);

#endif

