/* pr4_cdecl.c */
/* # I Do Declare */

#include <stdlib.h>
#include "pdecls.h"
#include "testfw.h"
#include "input.h"

#define BUFFERMAX 128

enum { NAME, PARENS, BRACKETS };
static int tokentype;
static char token[BUFFERMAX];
static char name[BUFFERMAX];
static char datatype [BUFFERMAX];
static char result[BUFFERMAX];

int gettoken(void)
{

}

void pr4_cdecl(void)
{
    char *line;

    printf("Enter a line of text: ");
    getline(&line, 2048);
    printf("You entered: %s", line);

    free(line);
}

int pr4_cdecl_tests(void)
{
    NOTEST
}
