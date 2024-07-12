#ifndef LBL_TESTFW_H
#define LBL_TESTFW_H

/* testfw.h */

#include <stdio.h>

extern int g_tr_s_;
extern int g_tr_f_;

#define NO_TESTS return 0;
#define ENCODE_TR(s, f) ((s & 0x0f) << 4 | f)
#define DECODE_TR_S(e) (e >> 4 & 0x0f)
#define DECODE_TR_F(e) (e & 0x0f)
#define TEST_DRIVER_RESET g_tr_s_ = 0; g_tr_f_ = 0;
#define TEST_DRIVER_REPORT return ENCODE_TR(g_tr_s_, g_tr_f_);

#define ASSERT_FN_DECL(name, ...) void testfw_##name(__VA_ARGS__, const char *file, int line);
#define ASSERT_FN(name, fail_cond, ...) void testfw_##name(__VA_ARGS__, const char *file, int line) { \
    if (fail_cond) { \
        printf("\t\033[31;1mFAIL:\033[0m %s failed on %s:%d\n", #name, file, line); \
        ++g_tr_f_; \
    } else { \
        ++g_tr_s_; \
    } \
}

ASSERT_FN_DECL(assert_is_true, int b)
#define assert_is_true(b) testfw_assert_is_true((b), __FILE__, __LINE__)

ASSERT_FN_DECL(assert_is_false, int b)
#define assert_is_false(b) testfw_assert_is_false((b), __FILE__, __LINE__)

ASSERT_FN_DECL(assert_streq, const char *s1, const char *s2)
#define assert_streq(s1, s2) testfw_assert_streq((s1), (s2), __FILE__, __LINE__)

#endif /* LBL_TESTFW_H */
