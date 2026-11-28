#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpMax3(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpMax3);
    int p1 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    int p2 = nums[0] * nums[1] * nums[numsSize - 1];
    return MAX(p1, p2);
}