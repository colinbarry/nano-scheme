#include <stdio.h>
#include <stdlib.h>
#include <picotest.h>

IMPORT_SUITE(lexer);

int main(int argc, char *argv[])
{
    BEGIN_TESTS();
    RUN_SUITE(lexer);

    printf("\n%s%i PASSED\n%i FAILED\n\e[39m", 
		   failures == 0 ? "\e[32m" : "\e[31m",
		   passes, 
		   failures);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
