/* pr13_roman_numerals.c */
/* # Decipher Roman Numerals */
/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M. */
/* ------ | ----- */
/* Symbol | Value */
/* ------ | ----- */
/* I      | 1     */
/* V      | 5     */
/* X      | 10    */
/* L      | 50    */
/* C      | 100   */
/* D      | 500   */
/* M      | 1000  */
/* ------ | ----- */
/* For example, 2 is written as II, 12 is written as XII, and 27 is written as XXVII. */
/* Roman numerals are usually written largest to smallest, from left to right, however */
/* the numeral for 4 is not IIII, but IV. Because the I is before the V, it is subtracted. */
/* The same principle applies to the numbers 9 (IX), 40 (XL), 90 (XC), 400 (CD), and 900 (CM). */
/* Given a roman numeral, convert it to an integer. */
/* Input: string, e.g. "MCMXCVI" */
/* Output: int, e.g. 1996 */
/* Output in case of invalid input: 0 */

#include "testfw.h"
#include "input.h"

static int decipher_roman(const char *s)
{
    int value = 0, max_next = 1000, mod = 0;

    while (*s) {
        int term;
        switch (*s++) {
            case 'M':
                term = 1000;
                break;
            case 'D':
                term = 500;
                mod = 1000;
                break;
            case 'C':
                term = (*s == 'M') ? 900 : (*s == 'D') ? 400 : 100;
                if (term != 100) {
                    s++;
                } else {
                    mod = 1000;
                }
                break;
            case 'L':
                term = 50;
                mod = 100;
                break;
            case 'X':
                term = (*s == 'C') ? 90 : (*s == 'L') ? 40 : 10;
                if (term != 10) {
                    s++;
                } else {
                    mod = 100;
                }
                break;
            case 'V':
                term = 5;
                mod = 10;
                break;
            case 'I':
                term = (*s == 'X') ? 9 : (*s == 'V') ? 4 : 1;
                if (term != 1) {
                    s++;
                } else {
                    mod = 10;
                }
                break;
            default:
                return 0;
        }

        if (term > max_next) {
            return 0;
        }

        value += term;

        switch (term) {
            case 900:
            case 400:
                max_next = 90;
                break;
            case 500:
            case 100:
                max_next = 100;
                if (((value % mod > 500) ? value % mod - 500 : value % mod) == 300) {
                    max_next = 90;
                }
                break;
            case 90:
            case 40:
                max_next = 9;
                break;
            case 50:
            case 10:
                max_next = 10;
                if (((value % mod > 50) ? value % mod - 50 : value % mod) == 30) {
                    max_next = 9;
                }
                break;
            case 9:
            case 4:
                max_next = 0;
                break;
            case 5:
            case 1:
                max_next = 1;
                if (((value % mod > 5) ? value % mod - 5 : value % mod) == 3) {
                    max_next = 0;
                }
                break;
        }
    }

    return value;
}

void pr13_roman_numerals(void)
{
    char *input;
    while (getline(&input, 128))
    {
        printf("%s >>> %d\n", input, decipher_roman(input));
    }
}

int pr13_roman_numerals_tests(void)
{
    NO_TESTS
}
