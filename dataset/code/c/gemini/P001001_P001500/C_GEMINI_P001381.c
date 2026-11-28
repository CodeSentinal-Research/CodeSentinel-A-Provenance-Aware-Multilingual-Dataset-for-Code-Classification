#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpLongest(const void* a, const void* b) {
    int v1 = *(int*)a, v2 = *(int*)b;
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmpLongest);

    int maxLen = 1, curLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) {
            curLen++;
        } else {
            maxLen = MAX(maxLen, curLen);
            curLen = 1;
        }
    }
    return MAX(maxLen, curLen);
}