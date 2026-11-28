#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int* prefix = (int*)malloc((numsSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) prefix[i + 1] = prefix[i] + nums[i];

    int ans = INT_MAX;
    for (int size = l; size <= r; size++) {
        for (int i = 0; i <= numsSize - size; i++) {
            int sum = prefix[i + size] - prefix[i];
            if (sum > 0) ans = MIN(ans, sum);
        }
    }
    free(prefix);
    return ans != INT_MAX ? ans : -1;
}