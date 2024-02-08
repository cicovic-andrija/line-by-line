#ifndef LBL_INTSET_H
#define LBL_INTSET_H

/* intset.h */

#include "bst.h"

typedef struct intset {
    s_bst_node *_bstp_root;
} s_intset;

s_intset empty_intset(void);

#endif /* LBL_INTSET_H */
