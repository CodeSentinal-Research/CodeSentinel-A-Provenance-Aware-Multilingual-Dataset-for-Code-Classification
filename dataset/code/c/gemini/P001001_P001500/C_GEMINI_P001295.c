#include <stdlib.h>

int cmpLong(const void* a, const void* b) {
    long long v1 = *(long long*)a, v2 = *(long long*)b;
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

long long putMarbles(int* weights, int weightsSize, int k) {
    if (k == 1 || k == weightsSize) return 0;

    long long* pairWeights = (long long*)malloc((weightsSize - 1) * sizeof(long long));
    for (int i = 0; i < weightsSize - 1; i++) {
        pairWeights[i] = (long long)weights[i] + weights[i + 1];
    }
    qsort(pairWeights, weightsSize - 1, sizeof(long long), cmpLong);

    long long minSum = 0, maxSum = 0;
    for (int i = 0; i < k - 1; i++) {
        minSum += pairWeights[i];
        maxSum += pairWeights[weightsSize - 2 - i];
    }

    free(pairWeights);
    return maxSum - minSum;
}