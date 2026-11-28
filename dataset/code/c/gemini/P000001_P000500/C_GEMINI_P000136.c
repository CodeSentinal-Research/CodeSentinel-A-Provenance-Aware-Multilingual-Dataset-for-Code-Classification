#include <stdlib.h>
#include <math.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            res[(*returnSize)++] = abs(nums[i]);
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return res;
}