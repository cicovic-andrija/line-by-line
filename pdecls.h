/* pdecls.h */
/* auto-generated */

#include "macros.h"

extern void (*pdptable[])(void);
extern int (*ptptable[])(void);
extern char *const pnames[];
extern char *const pcategories[];

#define PDESC(M) \
    M(pr0_var_hello, "Hello World", 0) \
    M(pr1_str_long_prefix, "The Longest Common String Prefix", 1) \

PDESC(PROB_DDECL)
PDESC(PROB_TDECL)
