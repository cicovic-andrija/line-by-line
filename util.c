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
