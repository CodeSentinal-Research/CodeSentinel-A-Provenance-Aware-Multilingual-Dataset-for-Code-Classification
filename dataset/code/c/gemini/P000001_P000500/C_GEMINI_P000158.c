#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxIncreasingSubarraySum(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    long long maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            curSum += nums[i];
        } else {
            curSum = nums[i];
        }
        maxSum = MAX(maxSum, curSum);
    }
    return maxSum;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("0\n");
        return 0;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    long long result = maxIncreasingSubarraySum(nums, n);
    printf("%lld\n", result);

    free(nums);
    return 0;
}
