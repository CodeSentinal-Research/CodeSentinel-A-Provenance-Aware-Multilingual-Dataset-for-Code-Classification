#include <stdlib.h>

int cmpFactors(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* getFactors(int n, int* returnSize) {
    if (n <= 0) {
        *returnSize = 0;  // write through pointer
        return NULL;
    }
    int* factors = (int*)malloc(2000 * sizeof(int));
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors[count++] = (int)i;
            if (i * i != n) factors[count++] = (int)(n / i);
        }
    }
    qsort(factors, count, sizeof(int), cmpFactors);
    *returnSize = count;  // write through pointer
    return factors;
}
