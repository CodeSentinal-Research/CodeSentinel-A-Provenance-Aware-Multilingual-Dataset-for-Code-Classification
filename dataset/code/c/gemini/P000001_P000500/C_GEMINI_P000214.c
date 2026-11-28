#include <stdlib.h>
#include <math.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        nums[idx] = -abs(nums[idx]);
    }

    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) res[(*returnSize)++] = i + 1;
    }
    return res;
}