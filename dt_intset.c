/* dt_intset.c */

#include "dt_intset.h"
#include "util.h"

intset intset_mint(void)
{
    intset set;
    set.tree = bst_mint(get_key_scalar_type, int_keycmp);
    return set;
}

int intset_search(intset *set, int i)
{
    return set ? bst_search(&set->tree, &i) != NULL : 0;
}

int intset_insert(intset *set, int i)
{
    if (set) {
        int *data = (int *)must_alloc(sizeof(int));
        *data = i;
        return bst_insert(&set->tree, data) || g_dterr == 0;
    }
    return 0;
}

int intset_remove(intset *set, int i)
{
    return set ? (bst_remove(&set->tree, &i) ? 1 : 0 ) : 0;
}

void intset_free(intset *set)
{
    if (set) {
        bst_visit(&set->tree, free, VISIT_POSTORDER);
        bst_free(&set->tree);
    }
}
