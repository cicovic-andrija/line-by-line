#ifndef LBL_PDECLS_H
#define LBL_PDECLS_H

/* pdecls.h */
/* auto-generated */

#include "macros.h"

extern void (*pdptable[])(void);
extern int (*ptptable[])(void);
extern char *pnames[];
extern char *pcategories[];

#define PDESC(M) \
    M(pr0_var_hello, "Hello World", 0) \
    M(pr1_str_long_prefix, "The Longest Common String Prefix", 1) \

typedef enum problem {
    PDESC(PROB_ENUM)
    PROB_COUNT
} e_problem;

PDESC(PROB_DDECL)
PDESC(PROB_TDECL)

#endif /* LBL_PDECLS_H */
