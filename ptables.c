/* ptables.c */

#include "pdecls.h"

static char *const categories[] = {
    "Various",          /* 0 */
    "Strings",          /* 1 */
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
