/* pr10_longest_prefix.c */
/* # Longest Common String Prefix */
/* Find the longest common prefix string for the strings present in the input array. */
/* Treat NULL elements of the input array as empty strings.*/
/* Input: array of strings, e.g. ["flower", "flow", "flight"] */
/* Output: string, e.g. "fl" */

#include <string.h>
#include "pdecls.h"
#include "util.h"
#include "testfw.h"

static char *longest_common_prefix(const char **input, int n)
{
    char *prefix, *p;
    int chi = 0;
    int end = 0;

    if (input == NULL || n < 1) return NULL;
    if (!input[0]) return "";

    p = prefix = (char *)must_alloc(strlen(input[0]) + 1);
    do {
        int i;
        char ch = input[0][chi];
        for (i = 0; i < n; ++i) {
            if (ch == '\0' || !input[i] || input[i][chi] == '\0' || ch != input[i][chi]) {
                end = 1;
                break;
            }
        }
        if (!end) {
            *p++ = ch;
            ++chi;
        }
    } while (!end);

    *p = '\0';
    return prefix;
}

void pr10_longest_prefix(void)
{

}

int pr10_longest_prefix_tests(void)
{
    const char *input_1[] = { "flower", "flow", "flight" };
    char *output_1 = longest_common_prefix(input_1, 3);

    const char *input_2[] = { "flow" };
    char *output_2 = longest_common_prefix(input_2, 1);

    const char *input_3[] = { "flower", NULL, "flow" };
    char *output_3 = longest_common_prefix(input_3, 3);

    const char *input_4[] = { "flower", "flow", "" };
    char *output_4 = longest_common_prefix(input_4, 3);

    const char *input_5[] = { "", "a", "aa", "aaa" };
    char *output_5 = longest_common_prefix(input_5, 4);

    TEST_DRIVER_RESET

    assert_streq("fl", output_1);
    assert_streq("flow", output_2);
    assert_streq("", output_3);
    assert_streq("", output_4);
    assert_streq("", output_5);

    free(output_1);
    free(output_2);
    free(output_3);
    free(output_4);
    free(output_5);

    TEST_DRIVER_REPORT
}
