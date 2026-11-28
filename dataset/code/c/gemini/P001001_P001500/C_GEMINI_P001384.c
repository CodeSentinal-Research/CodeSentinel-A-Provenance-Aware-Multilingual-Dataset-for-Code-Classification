#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            res[count++] = abs(nums[i]);
        } else {
            nums[idx] = -nums[idx];
        }
    }
    *returnSize = count;
    return res;
}