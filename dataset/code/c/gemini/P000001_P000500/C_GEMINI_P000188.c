#include <stdlib.h>

int* subarraySum(int* arr, int n, int target, int* returnSize) {
    int l = 0;
    long long curSum = 0;
    int* res = (int*)malloc(2 * sizeof(int));

    for (int r = 0; r < n; r++) {
        curSum += arr[r];
        while (curSum > target && l < r) {
            curSum -= arr[l++];
        }
        if (curSum == target) {
            *returnSize = 2;
            res[0] = l + 1;
            res[1] = r + 1;
            return res;
        }
    }
    *returnSize = 1;
    res[0] = -1;
    return res;
}