#include <stdlib.h>

int* printNosReverse(int n, int* returnSize) {
    *returnSize = n;  // write through pointer
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = n - i;
    return res;
}
