/* pr0_var_hello.c */
/* # Hello World */
/* Write the string "hello, world" to standard output. */

#include "pdecls.h"
#include "testfw.h"

static void hello_world(void)
{
    printf("hello, world\n");
}

void pr0_var_hello(void)
{
    hello_world();
}

int pr0_var_hello_tests(void)
{
    NOTEST
}
