#include <stdlib.h>

#define MOD 1000000007LL

int rev(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int cmpIntNice(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int countNicePairs(int* nums, int numsSize) {
    int* diffs = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        diffs[i] = nums[i] - rev(nums[i]);
    }
    qsort(diffs, numsSize, sizeof(int), cmpIntNice);

    long long ans = 0;
    long long count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (diffs[i] == diffs[i - 1]) {
            count++;
        } else {
            ans = (ans + count * (count - 1) / 2) % MOD;
            count = 1;
        }
    }
    ans = (ans + count * (count - 1) / 2) % MOD;

    free(diffs);
    return (int)ans;
}