/* dt_tests.c */

#include <stdio.h>
#include "util.h"
#include "testfw.h"

static void printi(void *pi)
{
    printf("%d", *(int *)pi);
}

static void printi_then_free(void *pi)
{
    printf("free(%d)\n", *(int *)pi);
    free(pi);
}

void dt_run_tests(void)
{
    printf("===\nRunning binary search tree tests...\n");
    {
        t_bst bst = bst_mint(get_key_scalar_type, int_keycmp);
        int values_to_remove[] = { 31, 14, 19 };
        int key;
        int *val;

        dbg_bst_insert(&bst, must_alloc_int(16), printi);
        dbg_bst_insert(&bst, must_alloc_int(14), printi);
        dbg_bst_insert(&bst, must_alloc_int(19), printi);
        dbg_bst_insert(&bst, must_alloc_int(11), printi);
        dbg_bst_insert(&bst, must_alloc_int(5), printi);
        dbg_bst_insert(&bst, must_alloc_int(17), printi);
        dbg_bst_insert(&bst, must_alloc_int(29), printi);
        dbg_bst_insert(&bst, must_alloc_int(12), printi);
        dbg_bst_insert(&bst, must_alloc_int(31), printi);
        dbg_bst_insert(&bst, must_alloc_int(21), printi);
        dbg_bst_insert(&bst, must_alloc_int(8), printi);
        dbg_bst_insert(&bst, must_alloc_int(26), printi);
        dbg_bst_insert(&bst, must_alloc_int(25), printi);
        dbg_bst_insert(&bst, must_alloc_int(27), printi);

        key = 11;
        assert_is_true((val = bst_search(&bst, &key)) != NULL && *val == key);

        key = 25;
        assert_is_true((val = bst_search(&bst, &key)) != NULL && *val == key);

        key = 42;
        assert_is_true(bst_search(&bst, &key) == NULL);

        val = (int *)dbg_bst_remove(&bst, &values_to_remove[0], printi);
        assert_inteq(*val, values_to_remove[0]);
        printi_then_free(val);
        key = values_to_remove[0];
        assert_is_true(bst_search(&bst, &key) == NULL);

        val = (int *)dbg_bst_remove(&bst, &values_to_remove[1], printi);
        assert_inteq(*val, values_to_remove[1]);
        printi_then_free(val);
        key = values_to_remove[1];
        assert_is_true(bst_search(&bst, &key) == NULL);

        val = (int *)dbg_bst_remove(&bst, &values_to_remove[2], printi);
        assert_inteq(*val, values_to_remove[2]);
        printi_then_free(val);
        key = values_to_remove[2];
        assert_is_true(bst_search(&bst, &key) == NULL);

        bst_visit(&bst, printi_then_free, VISIT_POSTORDER);
        bst_free(&bst);
    }
}
