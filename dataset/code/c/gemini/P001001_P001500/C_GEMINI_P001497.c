#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int pos = 0, neg = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[pos] = nums[i];
            pos += 2;
        } else {
            res[neg] = nums[i];
            neg += 2;
        }
    }

    *returnSize = numsSize;
    return res;
}