/* util.c */

#include <stdio.h>
#include "util.h"

int g_dterr = 0;

void *must_alloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        exit(ERR_OOM);
    }
    return p;
}

int *must_alloc_int(int val)
{
    int *p = must_alloc(sizeof(int));
    *p = val;
    return p;
}

void *get_key_scalar_type(void *data)
{
    return data;
}

int int_keycmp(void *key_1, void *key_2)
{
    return *((int *)key_1) - *((int *)key_2);
}
