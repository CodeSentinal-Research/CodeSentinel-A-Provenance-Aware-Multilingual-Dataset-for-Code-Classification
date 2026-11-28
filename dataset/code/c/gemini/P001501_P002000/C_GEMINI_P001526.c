#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSubArrayLen(int target, int* nums, int numsSize) {
    int l = 0, curSum = 0, ans = INT_MAX;

    for (int r = 0; r < numsSize; r++) {
        curSum += nums[r];
        while (curSum >= target) {
            ans = MIN(ans, r - l + 1);
            curSum -= nums[l++];
        }
    }
    return ans != INT_MAX ? ans : 0;
}