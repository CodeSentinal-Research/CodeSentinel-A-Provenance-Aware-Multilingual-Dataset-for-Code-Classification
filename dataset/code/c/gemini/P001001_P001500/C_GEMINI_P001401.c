#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArrayLen(int* nums, int numsSize, int k) {
    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum == k) {
                maxLen = MAX(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}