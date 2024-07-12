/* pr11_str_is_anagram.c */
/* # Nag A Ram */
/* Given two strings s and t, determine whether t is an anagram of s. */
/* Assume only lowercase letters a-z and spaces are present in input strings. Spaces should be ignored. */
/* Input: strings s and t, e.g. "tom marvolo riddle", "i am lord voldemort" */
/* Output: 1 if t is an anagram of s, 0 otherwise */

#include <ctype.h>
#include "pdecls.h"
#include "testfw.h"

static int is_anagram(const char *s, const char *t)
{
    int letters[26] = { 0 };
    int i = 0;
    const char *c;

    if (!s || !t) return 0;

    c = s;
    while (*c) {
        if (islower(*c)) letters[*c - 'a']++;
        c++;
    }

    c = t;
    while (*c) {
        if (islower(*c)) letters[*c - 'a']--;
        c++;
    }

    while (i < 26) if (letters[i++] > 0) return 0;

    return 1;
}

void pr11_str_is_anagram(void)
{

}

int pr11_str_is_anagram_tests(void)
{
    TEST_DRIVER_RESET

    assert_is_true(is_anagram("listen", "silent"));
    assert_is_true(is_anagram("tom marvolo riddle", "i am lord voldemort"));
    assert_is_false(is_anagram("notan", "anagram"));
    assert_is_false(is_anagram(NULL, "t"));
    assert_is_false(is_anagram("s", NULL));

    TEST_DRIVER_REPORT
}
