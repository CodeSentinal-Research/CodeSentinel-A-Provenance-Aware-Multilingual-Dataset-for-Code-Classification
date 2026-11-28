#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1 << numsSize;
    *returnSize = total;
    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    for (int mask = 0; mask < total; mask++) {
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) count++;
        }
        res[mask] = (int*)malloc(count * sizeof(int));
        (*returnColumnSizes)[mask] = count;

        int idx = 0;
        for (int i = 0; i < numsSize; i++) {
            if (mask & (1 << i)) res[mask][idx++] = nums[i];
        }
    }
    return res;
}