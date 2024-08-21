/* pr14_summed_subarrays.c */
/* # Subarray Sum Equals K */
/* Given an array of integers, and an integer K, return the total number of subarrays */
/* whose sum equals to K. A subarray is a contiguous non-empty sequence of elements within an array. */
/* Input: array of integers, e.g. [2, -2, 2, -2], and K = 0 */
/* Output: integer, e.g. 4 */

#include "util.h"
#include "testfw.h"

/* O(N) */
static int subarrays_of_sum_k_linear(int nums[], int n, int K)
{
    int count = 0;
    int *prefix_sums;
    t_iimap prefix_sum_counts = iimap_mint();
    int i;

    if (nums == NULL || n < 1) return 0;

    prefix_sums = (int *)must_alloc(n*sizeof(int));

    prefix_sums[0] = nums[0];
    for (i = 1; i < n; ++i) {
        prefix_sums[i] = prefix_sums[i-1] + nums[i];
    }

    for (i = 0; i < n; ++i) {
        int diff = prefix_sums[i] - K;
        intkv *sum_count_pair = iimap_search(&prefix_sum_counts, diff);
        if (sum_count_pair) {
            count += sum_count_pair->val;
        }
        sum_count_pair = iimap_search(&prefix_sum_counts, prefix_sums[i]);
        if (sum_count_pair) {
            sum_count_pair->val = sum_count_pair->val + 1;
        } else {
            intkv sum_count_pair_1;
            sum_count_pair_1.key = prefix_sums[i];
            sum_count_pair_1.val = 1;
            iimap_insert(&prefix_sum_counts, sum_count_pair_1);
        }
    }

    iimap_free(&prefix_sum_counts);
    free(prefix_sums);
    return count;
}

/* O(N^2) */
static int subarrays_of_sum_k_naive(int nums[], int n, int K)
{
    int count = 0;
    int i, j;

    if (nums == NULL || n < 1) return 0;

    for (i = 0; i < n; ++i) {
        int sum = 0;
        for (j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == K) {
                ++count;
            }
        }
    }

    return count;
}

void pr14_summed_subarrays(void)
{

}

int pr14_summed_subarrays_tests(void)
{
    int nums_1[] = { 1, 1, 1 };
    int K_1_1 = 2;
    int K_1_2 = 0;
    int K_1_3 = 1;

    int nums_2[] = { 5 };
    int K_2_1 = 5;
    int K_2_2 = 4;

    int nums_3[] = { 0, 5, -5, 5, -5 };
    int K_3 = 0;

    int nums_4[] = { 3, 4, 7, 2, -3, 1, 4, 2, 1 };
    int K_4 = 7;

    int (*fp[])(int[], int, int) = { subarrays_of_sum_k_naive, subarrays_of_sum_k_linear };

    /* unsigned long to prevent warning "comparison of integer expressions of different signedness". */
    unsigned long i;

    TEST_DRIVER_RESET

    for (i = 0; i < sizeof(fp)/sizeof(fp[0]); ++i) {
        int (*solution)(int[], int, int) = fp[i];

        assert_inteq(solution(NULL, 0, 0), 0);
        assert_inteq(solution(nums_1, 0, 0), 0);
        assert_inteq(solution(nums_1, sizeof(nums_1)/sizeof(int), K_1_1), 2);
        assert_inteq(solution(nums_1, sizeof(nums_1)/sizeof(int), K_1_2), 0);
        assert_inteq(solution(nums_1, sizeof(nums_1)/sizeof(int), K_1_3), 3);
        assert_inteq(solution(nums_1, sizeof(nums_1)/sizeof(int), K_1_3), 3);
        assert_inteq(solution(nums_2, sizeof(nums_2)/sizeof(int), K_2_1), 1);
        assert_inteq(solution(nums_2, sizeof(nums_2)/sizeof(int), K_2_2), 0);
        assert_inteq(solution(nums_3, sizeof(nums_3)/sizeof(int), K_3), 7);
        assert_inteq(solution(nums_4, sizeof(nums_4)/sizeof(int), K_4), 6);
    }

    TEST_DRIVER_REPORT
}
