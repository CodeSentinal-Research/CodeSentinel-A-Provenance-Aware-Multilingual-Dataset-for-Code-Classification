#include <limits.h>

int minCapability(int* nums, int numsSize, int k) {
    int left = INT_MAX, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < left) left = nums[i];
        if (nums[i] > right) right = nums[i];
    }
    int ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int count = 0;
        int i = 0;
        while (i < numsSize) {
            if (nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        if (count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}