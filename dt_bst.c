/* dt_bst.c */

#include "dt_bst.h"
#include "util.h"

static int bst_validate(t_bst *tree)
{
    return tree != NULL && tree->get_key != NULL && tree->keycmp != NULL;
}

static t_bst_node *bst_new_node(void)
{
    t_bst_node *new = (t_bst_node *)must_alloc(sizeof(t_bst_node));
    new->data = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}

t_bst bst_mint(void *(get_key_fn)(void *), int (*keycmp_fn)(void *, void *))
{
    t_bst tree;
    tree.root = NULL;
    tree.get_key = get_key_fn;
    tree.keycmp = keycmp_fn;
    return tree;
}

void *bst_search(t_bst *tree, void *key)
{
    t_bst_node *p;
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

static void bst_visit_nodes_preord(t_bst_node *root, void (*pfn)(void *))
{
    if (root) {
        pfn(root->data);
        bst_visit_nodes_preord(root->left, pfn);
        bst_visit_nodes_preord(root->right, pfn);
    }
}

static void bst_visit_nodes_inord(t_bst_node *root, void (*pfn)(void *))
{
    if (root) {
        bst_visit_nodes_inord(root->left, pfn);
        pfn(root->data);
        bst_visit_nodes_inord(root->right, pfn);
    }
}

static void bst_visit_nodes_postord(t_bst_node *root, void (*pfn)(void *))
{
    if (root) {
        bst_visit_nodes_postord(root->left, pfn);
        bst_visit_nodes_postord(root->right, pfn);
        pfn(root->data);
    }
}

void bst_visit(t_bst *tree, void (*pfn)(void *), e_visit_type vt)
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

int bst_insert(t_bst *tree, void *new_data, int update_existing)
{
    t_bst_node *new;
    t_bst_node *p, *q;
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
            if (!update_existing) {
                return 0; /* key already exists */
            }
            p->data = new_data;
            free(new); /* TODO: Handle this outside of bst implementation. */
            return 1;
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

void *bst_remove(t_bst *tree, void *key)
{
    t_bst_node *p, *q, *link;
    int cmpres;

    g_dterr = 0;

    if (!bst_validate(tree) || key == NULL) {
        g_dterr = ERR_INVALID_INPUT;
        return NULL;
    }

    p = tree->root;
    q = NULL;
    while (p != NULL && (cmpres = tree->keycmp(key, tree->get_key(p->data))) != 0) {
        q = p;
        p = cmpres < 0 ? q->left : q->right;
    }

    if (p == NULL) {
        return NULL; /* key not found */
    }

    if (p->left == NULL || p->right == NULL) {
        link = p->left ? p->left : p->right;
    } else {
        t_bst_node *f, *s;
        link = p->right;
        f = p;
        s = link->left;
        while (s != NULL) {
            f = link;
            link = s;
            s = link->left;
        }
        if (f != p) {
            f->left = link->right;
            link->right = p->right;
        }
        link->left = p->left;
    }

    if (q == NULL) {
        tree->root = link;
    } else if (p == q->left) {
        q->left = link;
    } else {
        q->right = link;
    }

    return p->data;
}

static void bst_free_nodes(t_bst_node *root) {
    if (root) {
        bst_free_nodes(root->left);
        bst_free_nodes(root->right);
        free(root);
    }
}

void bst_free(t_bst *tree)
{
    if (tree != NULL) {
        bst_free_nodes(tree->root);
        tree->root = NULL;
    }
}

/* dbg_* section. */

#include <stdio.h>

static void dbg_bst_print_nodes(t_bst_node *root, void (*repr)(void *))
{
    if (root) {
        repr(root->data);
        if (root->left || root->right) {
            printf(" > ");
            dbg_bst_print_nodes(root->left, repr);
            printf(" < ");
            dbg_bst_print_nodes(root->right, repr);
        }
        printf(" ^ ");
    }
}

int dbg_bst_insert(t_bst *tree, void *new_data, void (*repr)(void *))
{
    int inserted;
    printf("bst_insert("); repr(new_data);
    printf("): %s", (inserted = bst_insert(tree, new_data, 0)) ? "succeeded" : "failed");
    printf(", g_dterr = %d\n> bst = ", g_dterr);
    dbg_bst_print(tree, repr);
    putchar('\n');
    return inserted;
}

void *dbg_bst_remove(t_bst *tree, void *key, void (*repr)(void *))
{
    void *removed_data;
    printf("bst_remove("); repr(key);
    printf("): %s", (removed_data = bst_remove(tree, key)) ? "succeeded" : "failed");
    printf(", g_dterr = %d\n> bst = ", g_dterr);
    dbg_bst_print(tree, repr);
    putchar('\n');
    return removed_data;
}

void dbg_bst_print(t_bst *tree, void (*repr)(void *))
{
    if (tree) {
        dbg_bst_print_nodes(tree->root, repr);
    }
}
