#ifndef LBL_PDECLS_H
#define LBL_PDECLS_H

/* pdecls.h */

#include "macros.h"

extern void (*pdptable[])(void);
extern int (*ptptable[])(void);
extern char *pnames[];
extern char *pcategories[];
extern char *pdifficulties[];

/* How To Add a New Problem? */
/*   i) Come up with a shortcode for the problem, e.g. pr0_var_hello */
/*  ii) Make a file pr0_var_hello.c and implement two functions: */
/*       a) void pr0_var_hello(void); for interactive execution */
/*       b) int pr0_var_hello_tests(void); for running tests */
/* iii) Register the problem in the PDESC macro definition (below); check ptables.c for categories/difficulties */
/*  iv) Re-compile */

#define PDESC(M) \
    M(pr0_hello_world, "Hello, World!", 0, 0) \
    M(pr1_input_methods, "Try Out Input Methods", 0, 0) \
    M(pr10_longest_prefix, "Longest Common String Prefix", 1, 0) \
    M(pr11_str_is_anagram, "Nag A Ram", 1, 0) \
    M(pr12_happy_num, "Happy Who?", 2, 0) \
    M(pr13_roman_numerals, "Decipher Roman Numerals", 2, 0) \
    M(pr14_summed_subarrays, "Subarray Sum Equals K", 2, 2) \

typedef enum problem {
    PDESC(PROB_ENUM)
    PROB_COUNT
} e_problem;

PDESC(PROB_DDECL)
PDESC(PROB_TDECL)

#endif /* LBL_PDECLS_H */
