#include <stdlib.h>
#include <stdbool.h>

int cmpTriplet(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool find3Numbers(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpTriplet);
    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int curSum = nums[i] + nums[l] + nums[r];
            if (curSum == target) return true;
            else if (curSum < target) l++;
            else r--;
        }
    }
    return false;
}