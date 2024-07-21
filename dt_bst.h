#ifndef LBL_DT_BST_H
#define LBL_DT_BST_H

/* dt_bst.h */

typedef struct bst_node {
    void *data;
    struct bst_node *left;
    struct bst_node *right;
}
t_bst_node;

typedef struct bst {
    t_bst_node *root;
    void *(*get_key)(void *data);
    int (*keycmp)(void *key_1, void *key_2);
}
t_bst;

typedef enum visit_type {
    VISIT_PREORDER,
    VISIT_INORDER,
    VISIT_POSTORDER
}
e_visit_type;

t_bst bst_mint(void *(get_key_fn)(void *), int (*keycmp_fn)(void *, void *));
void *bst_search(t_bst *tree, void *key);
void bst_visit(t_bst *tree, void (*pfn)(void *), e_visit_type vt);
int bst_insert(t_bst *tree, void *new_data);
void *bst_remove(t_bst *tree, void *key);
void bst_free(t_bst *tree);

int dbg_bst_insert(t_bst *tree, void *new_data, void (*repr)(void *));
void *dbg_bst_remove(t_bst *tree, void *key, void (*repr)(void *));
void dbg_bst_print(t_bst *tree, void (*repr)(void *));

#endif /* LBL_DT_BST_H */
