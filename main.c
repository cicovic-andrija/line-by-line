/* main.c */

#include <stdio.h>
#include "pdecls.h"

#include "macros.h"
int main(int argc, char *argv[])
{
    int e;

    UNUSED(argc);
    UNUSED(argv);

    e = pr0_var_hello_tests();
    printf("%d\n%d\n", DECODE_TR_F(e), DECODE_TR_S(e));
    return 0;
}
