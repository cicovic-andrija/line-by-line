/* pr12_happy_num.c */
/* # Happy Who? */
/* Given a positive integer k, determine whether k is a happy number. */
/* Any number that reduces to one when you take the sum of the square of its digits and continue */
/* iterating until it yields one, is a happy number. */
/* Input: positive integer k, e.g. 379 */
/* Output: 1 if k is a happy number, 0 otherwise */

#include "pdecls.h"
#include "util.h"
#include "testfw.h"

static int digisum_sq(int k)
{
    int sum = 0;
    while (k > 0) {
        sum += (k % 10) * (k % 10);
        k = k / 10;
    }
    return sum;
}

static int is_happy(int k)
{
    intset set = intset_mint();
    int happy = 0;

    if (k < 1) {
        return 0;
    }

    while (1) {
        intset_insert(&set, k);
        k = digisum_sq(k);
        if (k == 1) {
            happy = 1;
            break;
        }
        if (intset_search(&set, k)) {
            break;
        }
    }

    intset_free(&set);
    return happy;
}

void pr12_happy_num(void)
{

}

int pr12_happy_num_tests(void)
{
    TEST_DRIVER_RESET

    assert_is_true(is_happy(1));
    assert_is_true(is_happy(313));
    assert_is_true(is_happy(331));
    assert_is_true(is_happy(367));
    assert_is_true(is_happy(379));
    assert_is_false(is_happy(4));
    assert_is_false(is_happy(0));

    TEST_DRIVER_REPORT
}
