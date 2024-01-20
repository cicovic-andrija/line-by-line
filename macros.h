#ifndef LBL_MACROS_H
#define LBL_MACROS_H

/* macros.h */

#define UNUSED(x) (void)(x)

#define PROB_NUM_ALL -1
#define PROB_DDECL(scode, name, cat, dif) void scode(void);
#define PROB_TDECL(scode, name, cat, dif) int scode##_tests(void);
#define PROB_ENUM(scode, name, cat, dif) e_##scode,
#define PROB_DFN(scode, name, cat, dif) scode,
#define PROB_TFN(scode, name, cat, dif) scode##_tests,
#define PROB_NAME(scode, name, cat, dif) name,
#define PROB_CAT(scode, name, cat, dif) categories[cat],
#define PROB_DIF(scode, name, cat, dif) difficulties[dif],

#endif /* LBL_MACROS_H */
