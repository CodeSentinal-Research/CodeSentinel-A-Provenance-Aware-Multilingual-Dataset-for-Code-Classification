#include <stdlib.h>

int countCompleteSubarrays(int* nums, int numsSize) {
    int seen[2005] = {0};
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i]]++ == 0) k++;
    }

    int count[2005] = {0};
    int distinct = 0, ans = 0, l = 0;

    for (int r = 0; r < numsSize; r++) {
        if (count[nums[r]]++ == 0) distinct++;
        while (distinct == k) {
            ans += numsSize - r;
            if (--count[nums[l]] == 0) distinct--;
            l++;
        }
    }
    return ans;
}