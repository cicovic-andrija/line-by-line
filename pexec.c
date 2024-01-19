/* pexec.c */

#include <stdio.h>
#include "pexec.h"
#include "testfw.h"

void run(int pr_num)
{
    pdptable[pr_num]();
}

void run_tests(int pr_num)
{
    int results;

    if (pr_num == PROB_NUM_ALL) {
        run_tests_for_all();
        return;
    }

    printf("===\nProblem #%d - %s\n", pr_num, pnames[pr_num]);
    results = ptptable[pr_num]();
    printf("\t--- Successful checks: %d\n\t--- Failed checks: %d\n", DECODE_TR_S(results), DECODE_TR_F(results));
}

void run_tests_for_all(void)
{
    int i;
    for (i = 0; i < PROB_COUNT; ++i) {
        run_tests(i);
    }
}

void help(void)
{
    printf(
        "lbl [action] [argument]\n"
        "   - action can be \"list\" (default), \"describe\", \"run\", \"test\" or \"help\"\n"
        "   - argument is a non-negative integer designating a problem\n"
        "\n"
        "lbl list       - list all available problems\n"
        "lbl describe N - describe a problem\n"
        "lbl run N      - run the solution for a problem against user input\n"
        "lbl test [N]   - run all programmed tests [for a problem]\n"
        "lbl help       - show this help message\n"
    );
}

void list(void)
{
    int i;
    const char *fmt_header = "%-3s  %-12s  %s\n";
    const char *fmt_row = "%-3d  %-12s  %s\n";

    printf(fmt_header, "N", "CATEGORY", "NAME");
    printf(fmt_header, "===", "============", "============");
    for (i = 0; i < PROB_COUNT; ++i) {
        printf(fmt_row, i, pcategories[i], pnames[i]);
    }
}

void describe(int pr_num)
{
    printf("===\nProblem #%d\n\n%s\n\nTODO\n", pr_num, pnames[pr_num]);
}
