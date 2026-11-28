#include <stdlib.h>

int* printNos(int n, int* returnSize) {
    *returnSize = n;  // write through pointer
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = i + 1;
    return res;
}
