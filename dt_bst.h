#ifndef LBL_DT_BST_H
#define LBL_DT_BST_H

/* dt_bst.h */

typedef struct _bst_node {
    void *data;
    struct _bst_node *left;
    struct _bst_node *right;
}
bst_node;

typedef struct _bst {
    bst_node *root;
    void *(*get_key)(void *data);
    int (*keycmp)(void *key_1, void *key_2);
}
bst;

typedef enum visit_type {
    VISIT_PREORDER,
    VISIT_INORDER,
    VISIT_POSTORDER
}
e_visit_type;

bst bst_mint(void);
void *bst_search(bst *tree, void *key);
void bst_visit(bst *tree, void (*pfn)(void *), e_visit_type vt);
int bst_insert(bst *tree, void *new_data);
int bst_remove(bst *tree, void *key);
void bst_free(bst *tree);

#endif /* LBL_DT_BST_H */
