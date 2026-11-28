#include <stdlib.h>

int cmpTripletsCnt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countTriplets(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpTripletsCnt);
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int curSum = nums[i] + nums[l] + nums[r];
            if (curSum == target) {
                count++;
                l++;
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return count;
}