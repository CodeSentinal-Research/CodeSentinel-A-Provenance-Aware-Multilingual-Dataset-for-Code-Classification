#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    for (int i = 0; i < numsSize && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    qsort(nums, numsSize, sizeof(int), cmpInt);
    // If current bit is set, multiply base into result
    if (k % 2 == 1) {
        nums[0] = -nums[0];
    }
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    return sum;
}