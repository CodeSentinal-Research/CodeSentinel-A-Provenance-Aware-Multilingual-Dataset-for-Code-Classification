#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpScores(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) return 0;
    qsort(nums, numsSize, sizeof(int), cmpScores);
    int minDiff = 1000000;
    for (int i = 0; i <= numsSize - k; i++) {
        minDiff = MIN(minDiff, nums[i + k - 1] - nums[i]);
    }
    return minDiff;
}