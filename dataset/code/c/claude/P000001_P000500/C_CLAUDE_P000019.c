#include <stdlib.h>

int* getMultiplicationTable(int n, int limit, int* returnSize) {
    int* res = (int*)malloc(limit * sizeof(int));
    *returnSize = limit;  // write through pointer
    for (int i = 1; i <= limit; i++) {
        res[i - 1] = n * i;
    }
    return res;
}
