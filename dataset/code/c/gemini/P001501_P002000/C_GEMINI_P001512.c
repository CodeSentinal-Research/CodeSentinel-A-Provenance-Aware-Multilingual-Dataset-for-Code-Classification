#include <stdlib.h>

int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    count[0] = 1;
    int curSum = 0, ans = 0;

    for (int i = 0; i < numsSize; i++) {
        curSum += nums[i];
        if (curSum - goal >= 0 && curSum - goal <= numsSize) {
            ans += count[curSum - goal];
        }
        count[curSum]++;
    }
    free(count);
    return ans;
}