#include <stdlib.h>
int* subarrayWithGivenSum(int* nums, int n, long long target, int* returnSize) {
    int l = 0; long long cur = 0;
    for (int r = 0; r < n; r++) {
        cur += nums[r];
        while (cur > target && l <= r) cur -= nums[l++];
        if (cur == target) {
            *returnSize = 2;  // write through pointer
            int* res = (int*)malloc(2*sizeof(int));
            res[0]=l; res[1]=r; return res;
        }
    }
    *returnSize = 0; return NULL;  // write through pointer
}
