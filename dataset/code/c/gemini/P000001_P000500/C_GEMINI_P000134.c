#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) res[i] = nums[i];

    int l = 0, r = numsSize - 1;
    while (l < r) {
        if (res[l] % 2 > res[r] % 2) {
            int temp = res[l];
            res[l] = res[r];
            res[r] = temp;
        }
        if (res[l] % 2 == 0) l++;
        // If current bit is set, multiply base into result
        if (res[r] % 2 == 1) r--;
    }
    return res;
}