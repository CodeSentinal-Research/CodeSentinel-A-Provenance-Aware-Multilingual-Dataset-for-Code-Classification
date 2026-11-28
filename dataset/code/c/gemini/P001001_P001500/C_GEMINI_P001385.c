#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0) nums[idx] = -nums[idx];
    }

    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) res[count++] = i + 1;
    }
    *returnSize = count;
    return res;
}