/* pr1_input_methods.c */
/* # Try Out Input Methods */
/* Implement a playground for trying out various input methods. */

#include "pdecls.h"
#include "testfw.h"
#include "util.h"
#include "input.h"

void pr1_input_methods(void)
{
    char *input;
    int n;

    printf("Please enter a line of text.\n"
        "(Example) Your input: the quick brown fox jumps over the lazy dog\n"
        "Your input: ");

    n = getline(&input, 1024);
    if (n > 0) {
        printf("You entered: %s\n<##>\n", input);
    } else {
        printf("An error occurred.\n");
    }

    free(input);
}

int pr1_input_methods_tests(void)
{
    NO_TESTS
}
