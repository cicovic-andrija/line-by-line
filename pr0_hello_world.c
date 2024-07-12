/* pr0_hello_world.c */
/* # Hello World */
/* Write the string "hello, world" to standard output. */

#include "pdecls.h"
#include "testfw.h"

static void hello_world(void)
{
    printf("hello, world\n");
}

void pr0_hello_world(void)
{
    hello_world();
}

int pr0_hello_world_tests(void)
{
    NO_TESTS
}
