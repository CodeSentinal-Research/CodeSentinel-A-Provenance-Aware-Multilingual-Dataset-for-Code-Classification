#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxLength(int* nums, int numsSize) {
    int* seen = (int*)malloc((2 * numsSize + 1) * sizeof(int));
    for (int i = 0; i <= 2 * numsSize; i++) seen[i] = -2;
    seen[numsSize] = -1;

    int curSum = 0, maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        curSum += (nums[i] == 1 ? 1 : -1);
        if (seen[curSum + numsSize] != -2) {
            maxLen = MAX(maxLen, i - seen[curSum + numsSize]);
        } else {
            seen[curSum + numsSize] = i;
        }
    }
    free(seen);
    return maxLen;
}