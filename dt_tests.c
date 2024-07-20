/* dt_tests.c */

#include <stdio.h>
#include "util.h"

void dt_run_tests(void)
{
    bst bst_0 = bst_mint();

    printf("===\nRunning data type tests:\n");

    /* Free everything. */
    bst_visit(&bst_0, free, VISIT_POSTORDER);
    bst_free(&bst_0);
}
