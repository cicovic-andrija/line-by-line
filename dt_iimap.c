/* dt_iimap.c */

#include "dt_iimap.h"
#include "util.h"

void *get_key_from_intkv(void *data)
{
    return &((intkv *)data)->key;
}

t_iimap iimap_mint(void)
{
    t_iimap map;
    map.tree = bst_mint(get_key_from_intkv, int_keycmp);
    return map;
}

intkv *iimap_search(t_iimap *map, int key)
{
    return map ? bst_search(&map->tree, &key) : NULL;
}

int iimap_insert(t_iimap *map, intkv kv)
{
    if (map) {
        intkv *data = (intkv *)must_alloc(sizeof(intkv));
        *data = kv;
        return bst_insert(&map->tree, data, 1 /* update_existing */);
    }
    return 0;
}

int iimap_remove(t_iimap *map, int key)
{
    /* TODO: Memory leak? No free. */
    return map ? (bst_remove(&map->tree, &key) ? 1 : 0 ) : 0;
}

void iimap_free(t_iimap *map)
{
    if (map) {
        bst_visit(&map->tree, free, VISIT_POSTORDER);
        bst_free(&map->tree);
    }
}
