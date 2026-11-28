#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    long long xorAll = 0;
    for (int i = 0; i < numsSize; i++) xorAll ^= nums[i];
    long long diff = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & diff) a ^= nums[i];
        else b ^= nums[i];
    }
    res[0] = a;
    res[1] = b;
    return res;
}