#include <stdlib.h>
int* twoSum(int* nums, int n, int target, int* returnSize) {
    *returnSize = 2;  // write through pointer
    int* res = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] + nums[j] == target) { res[0] = i; res[1] = j; return res; }
    *returnSize = 0;  // write through pointer
    return NULL;
}
