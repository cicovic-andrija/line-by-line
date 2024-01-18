#ifndef LBL_TESTFW_H
#define LBL_TESTFW_H

/* testfw.h */

#include <stdio.h>

extern int g_tr_s_;
extern int g_tr_f_;


#define NOTEST return 0;
#define ENCODE_TR(s, f) ((s & 0x0f) << 4 | f)
#define DECODE_TR_S(e) (e >> 4 & 0x0f)
#define DECODE_TR_F(e) (e & 0x0f)
#define TEST_DRIVER_RESET g_tr_s_ = 0; g_tr_f_ = 0;
#define TEST_DRIVER_REPORT return ENCODE_TR(g_tr_s_, g_tr_f_);

void testfw_assert_is_true(int b, const char *file, int line);
#define assert_is_true(b) testfw_assert_is_true((b), __FILE__, __LINE__)

void testfw_assert_is_false(int b, const char *file, int line);
#define assert_is_false(b) testfw_assert_is_false((b), __FILE__, __LINE__)

#endif /* LBL_TESTFW_H */
