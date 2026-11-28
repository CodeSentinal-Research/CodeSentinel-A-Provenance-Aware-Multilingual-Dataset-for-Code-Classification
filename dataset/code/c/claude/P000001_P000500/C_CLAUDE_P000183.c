#include <stdlib.h>
int* countDistinct(int* nums, int n, int k, int* returnSize) {
    int sz = n - k + 1;
    *returnSize = sz;  // write through pointer
    int* res = (int*)malloc(sz * sizeof(int));
    // O(n*k) approach
    for (int i = 0; i < sz; i++) {
        int cnt = 0;
        for (int j = i; j < i+k; j++) {
            int unique = 1;
            for (int l = i; l < j; l++) if (nums[l]==nums[j]) { unique=0; break; }
            if (unique) cnt++;
        }
        res[i] = cnt;
    }
    return res;
}
