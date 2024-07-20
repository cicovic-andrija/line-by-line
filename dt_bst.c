/* dt_bst.c */

#include "dt_bst.h"
#include "util.h"

static int bst_validate(bst *tree)
{
    return tree != NULL && tree->get_key != NULL && tree->keycmp != NULL;
}

static bst_node *bst_new_node(void)
{
    bst_node *new = (bst_node *)must_alloc(sizeof(bst_node));
    new->data = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

bst bst_mint(void)
{
    bst tree = { NULL, NULL, NULL };
    return tree;
}

void *bst_search(bst *tree, void *key)
{
    bst_node *p;
    int cmpres;

    g_dterr = 0;

    if (!bst_validate(tree) || key == NULL) {
        g_dterr = ERR_INVALID_INPUT;
        return NULL;
    }

    p = tree->root;
    while (p != NULL && (cmpres = tree->keycmp(key, tree->get_key(p->data))) != 0) {
        p = cmpres < 0 ? p->left : p->right;
    }
    return p ? p->data : NULL;
}

static void bst_visit_nodes_preord(bst_node *root, void (*pfn)(void *))
{
    if (root) {
        bst_visit_nodes_preord(root->left, pfn);
        bst_visit_nodes_preord(root->right, pfn);
        pfn(root->data);
    }
}

static void bst_visit_nodes_inord(bst_node *root, void (*pfn)(void *))
{
    if (root) {
        bst_visit_nodes_inord(root->left, pfn);
        pfn(root->data);
        bst_visit_nodes_inord(root->right, pfn);
    }
}

static void bst_visit_nodes_postord(bst_node *root, void (*pfn)(void *))
{
    if (root) {
        pfn(root->data);
        bst_visit_nodes_postord(root->left, pfn);
        bst_visit_nodes_postord(root->right, pfn);
    }
}

void bst_visit(bst *tree, void (*pfn)(void *), e_visit_type vt)
{
    g_dterr = 0;

    if (!bst_validate(tree) || pfn == NULL) {
        g_dterr = ERR_INVALID_INPUT;
        return;
    }

    switch (vt) {
    case VISIT_PREORDER:
        bst_visit_nodes_preord(tree->root, pfn);
        break;
    case VISIT_INORDER:
        bst_visit_nodes_inord(tree->root, pfn);
        break;
    case VISIT_POSTORDER:
        bst_visit_nodes_postord(tree->root, pfn);
        break;
    default:
        g_dterr = ERR_INVALID_INPUT;
        return;
    }
}

int bst_insert(bst *tree, void *new_data)
{
    bst_node *new;
    bst_node *p, *q;
    void *key;

    g_dterr = 0;

    if (!bst_validate(tree) || new_data == NULL || (key = tree->get_key(new_data)) == NULL) {
        g_dterr = ERR_INVALID_INPUT;
        return 0;
    }

    new = bst_new_node();
    new->data = new_data;

    p = tree->root;
    q = NULL;
    while (p != NULL) {
        int cmpres;
        q = p;
        if ((cmpres = tree->keycmp(key, tree->get_key(p->data))) == 0) {
            return 0; /* key already exists */
        } else if (cmpres < 0) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    if (q == NULL) {
        tree->root = new;
    } else if (tree->keycmp(key, tree->get_key(q->data)) < 0) {
        q->left = new;
    } else {
        q->right = new;
    }

    return 1;
}

int bst_remove(bst *tree, void *key)
{
    g_dterr = 0;

    if (!bst_validate(tree) || key == NULL) {
        g_dterr = ERR_INVALID_INPUT;
        return 0;
    }

    /* TODO. */

    return 1;
}

static void bst_free_nodes(bst_node *root) {
    if (root) {
        bst_free_nodes(root->left);
        bst_free_nodes(root->right);
        free(root);
    }
}

void bst_free(bst *tree)
{
    if (tree != NULL) {
        bst_free_nodes(tree->root);
    }
}
