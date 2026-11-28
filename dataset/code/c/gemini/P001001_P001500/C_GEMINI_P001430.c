#include <stdlib.h>

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int* res = (int*)malloc(ASize * sizeof(int));
    int* count = (int*)calloc(ASize + 1, sizeof(int));
    int common = 0;

    for (int i = 0; i < ASize; i++) {
        if (++count[A[i]] == 2) common++;
        if (++count[B[i]] == 2) common++;
        res[i] = common;
    }

    free(count);
    *returnSize = ASize;
    return res;
}