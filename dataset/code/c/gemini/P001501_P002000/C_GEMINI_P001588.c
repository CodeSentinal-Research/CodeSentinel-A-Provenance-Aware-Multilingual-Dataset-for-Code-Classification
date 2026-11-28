#include <stdlib.h>

int numberOfSubarrays(int* nums, int numsSize, int k) {
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    count[0] = 1;
    int curOdds = 0, ans = 0;

    for (int i = 0; i < numsSize; i++) {
        curOdds += (nums[i] % 2 != 0 ? 1 : 0);
        if (curOdds >= k) ans += count[curOdds - k];
        count[curOdds]++;
    }
    free(count);
    return ans;
}