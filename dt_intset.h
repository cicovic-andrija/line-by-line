#ifndef LBL_DT_INTSET_H
#define LBL_DT_INTSET_H

/* dt_intset.h */

#include "dt_bst.h"

typedef struct _intset {
    t_bst tree;
}
intset;

intset intset_mint(void);
int intset_search(intset *set, int i);
int intset_insert(intset *set, int i);
int intset_remove(intset *set, int i);
void intset_free(intset *set);

#endif /* LBL_DT_INTSET_H */
