#include <stdlib.h>

int cmpIntBad(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long countBadPairs(int* nums, int numsSize) {
    long long n = numsSize;
    long long totalPairs = n * (n - 1) / 2;

    int* diffs = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) diffs[i] = nums[i] - i;
    qsort(diffs, numsSize, sizeof(int), cmpIntBad);

    long long goodPairs = 0;
    long long count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (diffs[i] == diffs[i - 1]) {
            count++;
        } else {
            goodPairs += count * (count - 1) / 2;
            count = 1;
        }
    }
    goodPairs += count * (count - 1) / 2;

    free(diffs);
    return totalPairs - goodPairs;
}