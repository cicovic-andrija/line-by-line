#ifndef LBL_MACROS_H
#define LBL_MACROS_H

/* macros.h */

#define UNUSED(x) (void)(x)

#define PROB_NUM_ALL -1
#define PROB_DDECL(scode, name, cat) void scode(void);
#define PROB_TDECL(scode, name, cat) int scode##_tests(void);
#define PROB_ENUM(scode, name, cat) e_##scode,
#define PROB_DFN(scode, name, cat) scode,
#define PROB_TFN(scode, name, cat) scode##_tests,
#define PROB_NAME(scode, name, cat) name,
#define PROB_CAT(scode, name, cat) categories[cat],

#define ENCODE_TR(s, f) ((s & 0x0f) << 4 | f)
#define DECODE_TR_S(e) (e >> 4 & 0x0f)
#define DECODE_TR_F(e) (e & 0x0f)
#define TEST_DRIVER_START int tr_s_ = 0, tr_f_ = 0;
#define TEST_DRIVER_END return ENCODE_TR(tr_s_, tr_f_);
#define TEST_EXPECT_TRUE(b) { if (b) { ++tr_s_; } else { ++tr_f_; } }
#define TEST_EXPECT_FALSE(b) { if (!(b)) { ++tr_s_; } else { ++tr_f_; } }
#define TR_NOTESTS 0

#endif /* LBL_MACROS_H */
