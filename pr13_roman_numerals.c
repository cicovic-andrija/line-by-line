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
/* Output in case of invalid input: -1 */

#include "testfw.h"
#include "input.h"

#define ERR_INVALID -1

/* Returns the digit that should be multiplied by a power of 10. */
static int decipher_next_digit(char one_symbol, char five_symbol, char ten_symbol, const char **s)
{
    int digit = 0;
    int repeated = 0;

    if (**s == one_symbol) {
        char next;
        if ((next = *(*s + 1)) == five_symbol || next == ten_symbol) {
            *s += 2;
            return next == five_symbol ? 4 : 9;
        }
    } else if (**s == five_symbol) {
        digit += 5;
        ++*s;
    } else {
        return ERR_INVALID;
    }

    while (**s == one_symbol && repeated < 3) {
        digit++;
        repeated++;
        ++*s;
    }

    return digit;
}

static int decipher_roman(const char *s)
{
    int value = 0;
    int digit;

    if (s == NULL) {
        return ERR_INVALID;
    }

    while (*s == 'M') {
        value += 1000;
        s++;
    }

    if ((digit = decipher_next_digit('C', 'D', 'M', &s)) != ERR_INVALID) {
        value += digit * 100;
    }

    if ((digit = decipher_next_digit('X', 'L', 'C', &s)) != ERR_INVALID) {
        value += digit * 10;
    }

    if ((digit = decipher_next_digit('I', 'V', 'X', &s)) != ERR_INVALID) {
        value += digit;
    }

    return (*s || !value) ? ERR_INVALID : value;
}

void pr13_roman_numerals(void)
{
    char *input;
    printf("Keep entering roman numerals (enter EOF/interrupt to exit):\n");
    while (getline(&input, 128))
    {
        printf("%s >>> %d\n", input, decipher_roman(input));
    }
}

int pr13_roman_numerals_tests(void)
{
    TEST_DRIVER_RESET

    assert_inteq(decipher_roman("I"), 1);
    assert_inteq(decipher_roman("A"), ERR_INVALID);
    assert_inteq(decipher_roman("ACDC"), ERR_INVALID);
    assert_inteq(decipher_roman(""), ERR_INVALID);
    assert_inteq(decipher_roman(NULL), ERR_INVALID);
    assert_inteq(decipher_roman("XIA"), ERR_INVALID);
    assert_inteq(decipher_roman("0AI"), ERR_INVALID);
    assert_inteq(decipher_roman("M"), 1000);
    assert_inteq(decipher_roman("D"), 500);
    assert_inteq(decipher_roman("C"), 100);
    assert_inteq(decipher_roman("L"), 50);
    assert_inteq(decipher_roman("X"), 10);
    assert_inteq(decipher_roman("V"), 5);
    assert_inteq(decipher_roman("I"), 1);
    assert_inteq(decipher_roman("MCMXCVI"), 1996);
    assert_inteq(decipher_roman("XXV"), 25);
    assert_inteq(decipher_roman("XII"), 12);
    assert_inteq(decipher_roman("MMXIV"), 2014);
    assert_inteq(decipher_roman("MMMM"), 4000);
    assert_inteq(decipher_roman("MMVII"), 2007);
    assert_inteq(decipher_roman("MMXC"), 2090);
    assert_inteq(decipher_roman("MMXCIX"), 2099);
    assert_inteq(decipher_roman("CCV"), 205);
    assert_inteq(decipher_roman("LCCC"), ERR_INVALID);
    assert_inteq(decipher_roman("DCCCI"), 801);
    assert_inteq(decipher_roman("MDCVX"), ERR_INVALID);
    assert_inteq(decipher_roman("CLXXXX"), ERR_INVALID);
    assert_inteq(decipher_roman("IIII"), ERR_INVALID);
    assert_inteq(decipher_roman("LXVIV"), ERR_INVALID);
    assert_inteq(decipher_roman("LII"), 52);
    assert_inteq(decipher_roman("La13!II"), ERR_INVALID);
    assert_inteq(decipher_roman("MDCCCXLVIII"), 1848);

    TEST_DRIVER_REPORT
}
