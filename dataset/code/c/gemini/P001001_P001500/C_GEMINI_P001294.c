#include <stdlib.h>

int cmpIntDesc(const void* a, const void* b) {
    int v1 = *(int*)a, v2 = *(int*)b;
    if (v2 > v1) return 1;
    if (v2 < v1) return -1;
    return 0;
}

int maxScore(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpIntDesc);
    long long prefix = 0;
    int score = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i];
        if (prefix > 0) score++;
        else break;
    }
    return score;
}