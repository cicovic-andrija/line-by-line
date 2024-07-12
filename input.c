/* input.c */

#include <stdlib.h>
#include <stdio.h>
#include "input.h"

int getline(char **line, int lim)
{
    int c, i;
    char *s;

    if (line == NULL) {
        return 0;
    }

    if (lim < 1 || (*line = s = (char *)malloc(lim)) == NULL) {
        *line = NULL;
        return 0;
    }

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}
