#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    int total = 1 << n;
    *returnSize = total;
    int* res = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        res[i] = i ^ (i >> 1);
    }
    return res;
}