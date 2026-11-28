#include <stdlib.h>

int revNum(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int cmpIntDist(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countDistinct(int* nums, int numsSize) {
    int* all = (int*)malloc(2 * numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        all[2 * i] = nums[i];
        all[2 * i + 1] = revNum(nums[i]);
    }
    qsort(all, 2 * numsSize, sizeof(int), cmpIntDist);

    int count = 1;
    for (int i = 1; i < 2 * numsSize; i++) {
        if (all[i] != all[i - 1]) count++;
    }
    free(all);
    return count;
}