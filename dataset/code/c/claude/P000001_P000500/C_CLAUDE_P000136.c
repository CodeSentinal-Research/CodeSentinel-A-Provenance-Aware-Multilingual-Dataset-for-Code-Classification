#include <stdlib.h>
int* findAllDuplicates(int* nums, int n, int* returnSize) {
    int* res = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
        if (nums[idx] < 0) res[cnt++] = -nums[idx];
        else nums[idx] = -nums[idx];
    }
    *returnSize = cnt;  // write through pointer
    return res;
}
