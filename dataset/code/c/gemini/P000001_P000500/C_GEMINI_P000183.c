#include <stdlib.h>

int* countDistinct(int* arr, int n, int k, int* returnSize) {
    int* res = (int*)malloc((n - k + 1) * sizeof(int));
    *returnSize = n - k + 1;

    for (int i = 0; i <= n - k; i++) {
        int distinct = 0;
        for (int j = i; j < i + k; j++) {
            int isFirst = 1;
            for (int p = i; p < j; p++) {
                if (arr[p] == arr[j]) {
                    isFirst = 0;
                    break;
                }
            }
            if (isFirst) distinct++;
        }
        res[i] = distinct;
    }
    return res;
}