#include <stdlib.h>
#include <math.h>

int cmp3Sum(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp3Sum);
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int curSum = nums[i] + nums[l] + nums[r];
            if (abs(curSum - target) < abs(closest - target)) {
                closest = curSum;
            }
            if (curSum < target) l++;
            else if (curSum > target) r--;
            else return target;
        }
    }
    return closest;
}