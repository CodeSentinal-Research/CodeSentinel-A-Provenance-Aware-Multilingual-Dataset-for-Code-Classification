#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int findShortestSubArray(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    int* count = (int*)calloc(maxVal + 1, sizeof(int));
    int* first = (int*)malloc((maxVal + 1) * sizeof(int));
    int* last = (int*)malloc((maxVal + 1) * sizeof(int));
    for (int i = 0; i <= maxVal; i++) first[i] = -1;

    int degree = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (first[x] == -1) first[x] = i;
        last[x] = i;
        count[x]++;
        if (count[x] > degree) degree = count[x];
    }

    int minLen = numsSize;
    for (int i = 0; i <= maxVal; i++) {
        if (count[i] == degree) {
            minLen = MIN(minLen, last[i] - first[i] + 1);
        }
    }

    free(count);
    free(first);
    free(last);
    return minLen;
}