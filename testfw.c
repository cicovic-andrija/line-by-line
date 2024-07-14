/* testfw.c */

#include <string.h>
#include "testfw.h"
#include "macros.h"

int g_tr_s_ = 0;
int g_tr_f_ = 0;

ASSERT_FN(assert_is_true, !b, int b)

ASSERT_FN(assert_is_false, b, int b)

ASSERT_FN(assert_streq, strcmp(s1, s2), const char *s1, const char *s2)

ASSERT_FN(assert_inteq, i1 != i2, int i1, int i2)
