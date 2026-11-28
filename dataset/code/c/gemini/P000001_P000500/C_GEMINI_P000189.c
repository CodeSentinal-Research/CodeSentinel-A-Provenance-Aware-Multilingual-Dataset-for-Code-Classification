#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int maxSum = nums[0], curMax = 0;
    int minSum = nums[0], curMin = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        curMax = MAX(x, curMax + x);
        maxSum = MAX(maxSum, curMax);

        curMin = MIN(x, curMin + x);
        minSum = MIN(minSum, curMin);

        total += x;
    }

    return maxSum < 0 ? maxSum : MAX(maxSum, total - minSum);
}