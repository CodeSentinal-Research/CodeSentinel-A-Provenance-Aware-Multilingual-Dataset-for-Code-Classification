#include <stdlib.h>

int* applyOperations(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int* res = (int*)calloc(numsSize, sizeof(int));
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) res[idx++] = nums[i];
    }

    *returnSize = numsSize;
    return res;
}