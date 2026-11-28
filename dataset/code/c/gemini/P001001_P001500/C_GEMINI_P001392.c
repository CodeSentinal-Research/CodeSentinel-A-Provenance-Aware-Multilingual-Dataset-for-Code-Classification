#include <stdlib.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
    int* count = (int*)calloc(k, sizeof(int));
    count[0] = 1;
    int prefix = 0, ans = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix = (prefix + nums[i]) % k;
        if (prefix < 0) prefix += k;
        ans += count[prefix];
        count[prefix]++;
    }
    free(count);
    return ans;
}