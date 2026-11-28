#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int deleteAndEarn(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    int* count = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]] += nums[i];
    }

    int rob1 = 0, rob2 = 0;
    for (int i = 0; i <= maxVal; i++) {
        int tmp = MAX(rob1 + count[i], rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    free(count);
    return rob2;
}