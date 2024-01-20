/* ptables.c */

#include "pdecls.h"

static char *const categories[] = {
    "Various",          /* 0 */
    "Strings",          /* 1 */
};

static char *const difficulties[] = {
#ifndef LOZBOTW_MOD
    "Beginner",         /* 0 */
    "Intermediate",     /* 1 */
    "Advanced",         /* 2 */
    "Expert",           /* 3 */
#else
    "Tiny Korok",       /* 0 */
    "Princess Zelda",   /* 1 */
    "Royal Knight",     /* 2 */
    "Champion",         /* 3 */
#endif
};

void (*pdptable[])(void) = {
    PDESC(PROB_DFN)
};

int (*ptptable[])(void) = {
    PDESC(PROB_TFN)
};

char *pnames[] = {
    PDESC(PROB_NAME)
};

char *pcategories[] = {
    PDESC(PROB_CAT)
};

char *pdifficulties[] = {
    PDESC(PROB_DIF)
};
