#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpProd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpProd);
    return MAX(nums[0] * nums[1], nums[numsSize - 1] * nums[numsSize - 2]);
}