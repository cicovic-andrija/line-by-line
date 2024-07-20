/* input.c */

#include <stdio.h>
#include "util.h"
#include "input.h"

int getline(char **line, int lim)
{
    int c, i;
    char *s;

    if (line == NULL) {
        return 0;
    }
    if (lim < 1) {
        *line = NULL;
        return 0;
    }

    *line = s = (char *)must_alloc(lim);
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    /* Consume the rest of the line. */
    while (c != '\n' && (c = getchar()) != EOF) {
        ;
    }

    return i;
}
