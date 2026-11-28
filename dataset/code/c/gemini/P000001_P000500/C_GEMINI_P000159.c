#define MIN(a, b) ((a) < (b) ? (a) : (b))

int smallestSumSubarray(int* nums, int numsSize) {
    int minSum = nums[0], curSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        curSum = MIN(nums[i], curSum + nums[i]);
        minSum = MIN(minSum, curSum);
    }
    return minSum;
}