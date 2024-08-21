#ifndef LBL_UTIL_H
#define LBL_UTIL_H

/* util.h */

#include <stdlib.h>
#include "dt_intpair.h"
#include "dt_bst.h"
#include "dt_intset.h"
#include "dt_iimap.h"

extern int g_dterr;
enum {
    ERR_OOM = 1,
    ERR_INVALID_INPUT = 16
};

void *must_alloc(size_t size);
int *must_alloc_int(int val);
void *get_key_scalar_type(void *data);
int int_keycmp(void *key_1, void *key_2);

#endif /* LBL_UTIL_H */
