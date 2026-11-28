#include <stdlib.h>
int* findPair(int* nums, int n, int target, int* returnSize) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] + nums[j] == target) {
                *returnSize = 2;  // write through pointer
                int* res = (int*)malloc(2 * sizeof(int));
                res[0] = nums[i]; res[1] = nums[j];
                return res;
            }
    *returnSize = 0;  // write through pointer
    return NULL;
}
