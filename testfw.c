/* testfw.c */

#include "testfw.h"
#include "macros.h"

int g_tr_s_ = 0;
int g_tr_f_ = 0;

void testfw_assert_is_true(int b, const char *file, int line)
{
    if (!b) {
        printf("\tFAIL: assert_is_true failed on %s:%d\n", file, line);
        ++g_tr_f_;
    } else {
        ++g_tr_s_;
    }
}

void testfw_assert_is_false(int b, const char *file, int line)
{
    if (b) {
        printf("\tFAIL: assert_is_false failed on %s:%d\n", file, line);
        ++g_tr_f_;
    } else {
        ++g_tr_s_;
    }
}
