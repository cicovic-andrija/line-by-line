/* dt_intset.c */

#include "dt_intset.h"
#include "util.h"

void *intset_get_key(void *data)
{
    return data;
}

int intset_keycmp(void *key_1, void *key_2)
{
    return *((int *)key_1) - *((int *)key_2);
}

intset intset_mint(void)
{
    intset set;
    set.tree = bst_mint();
    set.tree.get_key = intset_get_key;
    set.tree.keycmp = intset_keycmp;
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
    return set ? bst_remove(&set->tree, &i) : 0;
}

void intset_free(intset *set)
{
    if (set) {
        bst_visit(&set->tree, free, VISIT_POSTORDER);
        bst_free(&set->tree);
    }
}
