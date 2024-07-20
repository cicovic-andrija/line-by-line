#ifndef LBL_UTIL_H
#define LBL_UTIL_H

/* util.h */

#include <stdlib.h>
#include "dt_bst.h"
#include "dt_intset.h"

extern int g_dterr;
enum {
    ERR_OOM = 1,
    ERR_INVALID_INPUT = 16
};

void *must_alloc(size_t size);

#endif /* LBL_UTIL_H */
