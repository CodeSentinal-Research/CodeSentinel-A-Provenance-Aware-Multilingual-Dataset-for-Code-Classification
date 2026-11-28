#define MAX(a, b) ((a) > (b) ? (a) : (b))

double findMaxAverage(int* nums, int numsSize, int k) {
    double curSum = 0;
    for (int i = 0; i < k; i++) curSum += nums[i];
    double maxSum = curSum;

    for (int i = k; i < numsSize; i++) {
        curSum += nums[i] - nums[i - k];
        maxSum = MAX(maxSum, curSum);
    }
    return maxSum / k;
}