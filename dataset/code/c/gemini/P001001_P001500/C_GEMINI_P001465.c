#include <stdlib.h>
#include <math.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int l = 0, r = numsSize - 1, pos = numsSize - 1;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r])) {
            res[pos] = nums[l] * nums[l];
            l++;
        } else {
            res[pos] = nums[r] * nums[r];
            r--;
        }
        pos--;
    }
    return res;
}