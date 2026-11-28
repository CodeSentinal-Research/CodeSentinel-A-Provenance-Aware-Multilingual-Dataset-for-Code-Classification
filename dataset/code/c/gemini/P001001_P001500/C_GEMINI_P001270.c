#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minOperations(int* nums, int numsSize, int x) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    int target = total - x;
    if (target < 0) return -1;
    if (target == 0) return numsSize;

    int curSum = 0, maxLen = -1, l = 0;
    for (int r = 0; r < numsSize; r++) {
        curSum += nums[r];
        while (curSum > target && l <= r) {
            curSum -= nums[l++];
        }
        if (curSum == target) {
            maxLen = MAX(maxLen, r - l + 1);
        }
    }
    return maxLen == -1 ? -1 : numsSize - maxLen;
}