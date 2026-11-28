#include <stdlib.h>

int* fibonacciSeries(int n, int* returnSize) {
    *returnSize = n;  // write through pointer
    if (n <= 0) return NULL;
    int* res = (int*)malloc(n * sizeof(int));
    if (n >= 1) res[0] = 0;
    if (n >= 2) res[1] = 1;
    for (int i = 2; i < n; i++) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res;
}
