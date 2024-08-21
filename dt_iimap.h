#ifndef LBL_DT_IIMAP_H
#define LBL_DT_IIMAP_H

/* dt_iimap.h */

#include "dt_intpair.h"
#include "dt_bst.h"

typedef struct iimap {
    t_bst tree;
}
t_iimap;

t_iimap iimap_mint(void);
intkv *iimap_search(t_iimap *map, int key);
int iimap_insert(t_iimap *map, intkv kv);
int iimap_remove(t_iimap *map, int kv);
void iimap_free(t_iimap *map);

#endif /* LBL_DT_IIMAP_H */
