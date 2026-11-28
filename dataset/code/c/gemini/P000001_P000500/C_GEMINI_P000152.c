#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpMinProd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpMinProd);
    return MIN(nums[0] * nums[numsSize - 1], MIN(nums[0] * nums[1], nums[numsSize - 1] * nums[numsSize - 2]));
}