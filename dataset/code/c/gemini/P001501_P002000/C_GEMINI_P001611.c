#include <stdlib.h>

#define MIN(a, b) ((a) > (b) ? (a) : (b))

int shortestSubarray(int* nums, int numsSize, int k) {
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) prefix[i + 1] = prefix[i] + nums[i];

    int* dq = (int*)malloc((numsSize + 1) * sizeof(int));
    int head = 0, tail = 0;
    int minLen = numsSize + 1;

    for (int i = 0; i <= numsSize; i++) {
        while (tail > head && prefix[i] - prefix[dq[head]] >= k) {
            minLen = MIN(minLen, i - dq[head++]);
        }
        while (tail > head && prefix[i] <= prefix[dq[tail - 1]]) {
            tail--;
        }
        dq[tail++] = i;
    }

    free(prefix);
    free(dq);
    return minLen <= numsSize ? minLen : -1;
}