#include <stdlib.h>

int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* prefix = (int*)malloc((arrSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < arrSize; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    int* res = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0], r = queries[i][1];
        res[i] = prefix[r + 1] ^ prefix[l];
    }
    free(prefix);
    return res;
}