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
    if (results != 0) {
        printf("\t--- Successful checks: %d\n\t--- Failed checks: %d\n", DECODE_TR_S(results), DECODE_TR_F(results));
        printf("\t>>> %s\033[0m\n", DECODE_TR_F(results) > 0 ? "\033[31;1mFAIL!" : "\033[32;1mSUCCESS");
    } else {
        printf("\t>>> \033[36;1mNO TESTS FOUND\033[0m\n");
    }

}

void run_tests_for_all(void)
{
    int i;
    for (i = 0; i < PROB_COUNT; ++i) {
        run_tests(i);
    }
}

void run_internal_tests(void)
{
    void dt_run_tests(void);

    dt_run_tests();
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
    const char *fmt_header = "%-3s  %-16s  %-16s  %s\n";
    const char *fmt_row = "%-3d  %-16s  %-16s  %s\n";

    printf(fmt_header, "N", "CATEGORY", "DIFFICULTY", "NAME");
    printf(fmt_header, "===", "================", "================", "================");
    for (i = 0; i < PROB_COUNT; ++i) {
        printf(fmt_row, i, pcategories[i], pdifficulties[i], pnames[i]);
    }
}

void describe(int pr_num)
{
    printf("===\nProblem #%d | Category: %s | Difficulty: %s\n\n%s\n\nproblem description (TODO)\n",
        pr_num, pcategories[pr_num], pdifficulties[pr_num], pnames[pr_num]);
}
