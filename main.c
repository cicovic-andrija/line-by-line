/* main.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "pexec.h"

typedef enum action {
    A_LIST,
    A_DESC,
    A_RUN,
    A_TEST,
    A_TEST_INTERNAL,
    A_HELP,
    A_INVALID
}
e_action;

typedef struct user_request {
    e_action action;
    int pr_num;
    const char *err_msg;
}
s_user_request;

void str_scan_action(const char *str, e_action *action)
{
    if (!strcmp(str, "list"))
    {
        *action = A_LIST;
    }
    else if (!strcmp(str, "describe"))
    {
        *action = A_DESC;
    }
    else if (!strcmp(str, "run"))
    {
        *action = A_RUN;
    }
    else if (!strcmp(str, "test"))
    {
        *action = A_TEST;
    }
    else if (!strcmp(str, "__test"))
    {
        *action = A_TEST_INTERNAL;
    }
    else if (!strcmp(str, "help"))
    {
        *action = A_HELP;
    }
}

int str_scan_int(const char *str, int *i, int min_i, int max_i, const char **err_msg)
{
    long L;
    char *end;

    errno = 0;
    L = strtol(str, &end, 10);

    if (end == str) {
        *err_msg = "invalid argument";
        return 1;
    }

    if (((L == LONG_MAX || L == LONG_MIN) && errno == ERANGE) || (L > max_i || L < min_i)) {
        *err_msg = "argument out of bounds";
        return 1;
    }

    *i = (int)L;
    return 0;
}

s_user_request parse_program_input(int argc, char *argv[])
{
    s_user_request req;
    req.action = A_INVALID;
    req.pr_num = PROB_NUM_ALL;
    req.err_msg = NULL;

    switch (argc) {
        case 1:
            req.action = A_LIST;
            break;
        case 2:
            str_scan_action(argv[1], &req.action);
            if (req.action == A_DESC || req.action == A_RUN)
            {
                req.err_msg = "insufficient arguments";
            }
            break;
        case 3:
            str_scan_action(argv[1], &req.action);
            str_scan_int(argv[2], &req.pr_num, 0, PROB_COUNT-1, &req.err_msg);
            break;
    }

    if (req.action == A_INVALID) {
        req.err_msg = "invalid action";
    }

    return req;
}

int main(int argc, char *argv[])
{
    s_user_request req = parse_program_input(argc, argv);
    if (req.err_msg != NULL)
    {
        printf("%s\n", req.err_msg);
        return 1;
    }

    switch (req.action)
    {
        case A_LIST:
            list();
            break;
        case A_DESC:
            describe(req.pr_num);
            break;
        case A_RUN:
            run(req.pr_num);
            break;
        case A_TEST:
            run_tests(req.pr_num);
            break;
        case A_TEST_INTERNAL:
            run_internal_tests();
            break;
        case A_HELP:
            help();
            break;
        default:
            break;
    }

    return 0;
}
