#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpIntPairSum(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpIntPairSum);
    int maxPair = 0;
    for (int i = 0; i < numsSize / 2; i++) {
        maxPair = MAX(maxPair, nums[i] + nums[numsSize - 1 - i]);
    }
    return maxPair;
}