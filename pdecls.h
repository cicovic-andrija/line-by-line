#ifndef LBL_PDECLS_H
#define LBL_PDECLS_H

/* pdecls.h */

#include "macros.h"

extern void (*pdptable[])(void);
extern int (*ptptable[])(void);
extern char *pnames[];
extern char *pcategories[];
extern char *pdifficulties[];

#define PDESC(M) \
    M(pr0_var_hello, "Hello World", 0, 0) \
    M(pr1_str_long_prefix, "Longest Common String Prefix", 1, 0) \
    M(pr2_str_is_anagram, "Nag A Ram", 1, 0) \
    M(pr3_var_happy_num, "Happy Who?", 2, 0) \
    M(pr4_cdecl, "I Do Declare", 0, 2) \
    M(pr5_p_probability, "P Probability", 2, 1) \

typedef enum problem {
    PDESC(PROB_ENUM)
    PROB_COUNT
} e_problem;

PDESC(PROB_DDECL)
PDESC(PROB_TDECL)

#endif /* LBL_PDECLS_H */
