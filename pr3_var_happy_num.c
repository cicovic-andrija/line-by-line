/* pr3_var_happy_num.c */
/* # Happy Who? */
/* Given a positive integer k, determine whether k is a happy number. */
/* Any number that reduces to one when you take the sum of the square of its digits and continue */
/* iterating until it yields one, is a happy number. */
/* Input: positive integer k, e.g. 379 */
/* Output: 1 if k is a happy number, 0 otherwise */

#include "pdecls.h"
#include "testfw.h"

int is_happy(int k)
{
    return 0;
}

void pr3_var_happy_num(void)
{

}

int pr3_var_happy_num_tests(void)
{
    TEST_DRIVER_RESET

    assert_is_true(is_happy(313));
    assert_is_true(is_happy(331));
    assert_is_true(is_happy(367));
    assert_is_true(is_happy(379));
    assert_is_false(is_happy(4));

    TEST_DRIVER_REPORT
}
