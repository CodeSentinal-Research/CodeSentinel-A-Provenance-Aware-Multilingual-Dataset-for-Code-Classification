#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minMoves(int* nums, int numsSize, int k) {
    int* p = (int*)malloc(numsSize * sizeof(int));
    int pSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) p[pSize++] = i;
    }

    long long* presum = (long long*)calloc(pSize + 1, sizeof(long long));
    for (int i = 0; i < pSize; i++) presum[i + 1] = presum[i] + p[i];

    long long ans = LLONG_MAX;
    int radius = (k - 1) / 2;

    for (int i = radius; i < pSize - k + radius + 1; i++) {
        long long right = presum[i + k - radius] - presum[i + 1];
        long long left = presum[i] - presum[i - radius];
        ans = MIN(ans, right - left);
    }

    long long offset = (long long)radius * (radius + 1);
    if (k % 2 == 0) offset += (radius + 1);

    free(p);
    free(presum);
    return (int)(ans - offset);
}