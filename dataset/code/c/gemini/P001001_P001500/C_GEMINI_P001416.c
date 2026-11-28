#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpIntLHS(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpIntLHS);
    int ans = 0;
    int l = 0;

    for (int r = 0; r < numsSize; r++) {
        while (nums[r] - nums[l] > 1) l++;
        if (nums[r] - nums[l] == 1) {
            ans = MAX(ans, r - l + 1);
        }
    }
    return ans;
}