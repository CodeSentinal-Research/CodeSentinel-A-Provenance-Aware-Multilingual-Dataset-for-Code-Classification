#include <stdbool.h>
#include <stdlib.h>

int cmpArith(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    bool* res = (bool*)malloc(lSize * sizeof(bool));
    *returnSize = lSize;

    for (int i = 0; i < lSize; i++) {
        int len = r[i] - l[i] + 1;
        int* sub = (int*)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) sub[j] = nums[l[i] + j];
        qsort(sub, len, sizeof(int), cmpArith);

        bool isArith = true;
        int diff = sub[1] - sub[0];
        for (int j = 2; j < len; j++) {
            if (sub[j] - sub[j - 1] != diff) {
                isArith = false;
                break;
            }
        }
        res[i] = isArith;
        free(sub);
    }
    return res;
}