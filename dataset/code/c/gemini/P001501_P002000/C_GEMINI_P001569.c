#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumUniqueSubarray(int* nums, int numsSize) {
    int seen[10005] = {0};
    int l = 0, curSum = 0, maxSum = 0;

    for (int r = 0; r < numsSize; r++) {
        int num = nums[r];
        while (seen[num]) {
            seen[nums[l]] = 0;
            curSum -= nums[l++];
        }
        seen[num] = 1;
        curSum += num;
        maxSum = MAX(maxSum, curSum);
    }
    return maxSum;
}