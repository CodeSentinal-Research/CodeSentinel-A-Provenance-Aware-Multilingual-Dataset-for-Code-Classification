#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* res = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* dq = (int*)malloc(numsSize * sizeof(int));
    int head = 0, tail = 0;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        while (tail > head && nums[dq[tail - 1]] <= nums[i]) tail--;
        dq[tail++] = i;

        while (dq[head] <= i - k) head++;

        if (i >= k - 1) {
            res[idx++] = nums[dq[head]];
        }
    }

    free(dq);
    *returnSize = idx;
    return res;
}