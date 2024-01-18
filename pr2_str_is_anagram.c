/* pr2_str_is_anagram.c */
/* # Nag A Ram */
/* Given two strings s and t, return 1 if t is an anagram of s. Otherwise, return 0. */
/* Assume only lowercase letters a-z are present in input strings. */
/* Input: two strings, e.g. "listen", "silent" */
/* Output: integer, e.g. 1 */

#include "pdecls.h"
#include "testfw.h"

int is_anagram(const char *s, const char *t)
{
    int letters[26] = { 0 };
    int i = 0;
    const char *c;

    if (!s || !t) return 0;

    c = s;
    while (*c) {
        letters[*c - 'a']++;
        c++;
    }

    c = t;
    while (*c) {
        letters[*c - 'a']--;
        c++;
    }

    while (i < 26) if (letters[i++] > 0) return 0;

    return 1;
}

void pr2_str_is_anagram(void)
{

}

int pr2_str_is_anagram_tests(void)
{
    TEST_DRIVER_RESET

    assert_is_true(is_anagram("anagram", "nagaram"));
    assert_is_true(is_anagram("abc", "acb"));

    TEST_DRIVER_REPORT
}
