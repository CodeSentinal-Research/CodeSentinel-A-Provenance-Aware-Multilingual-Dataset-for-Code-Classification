#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* primesInRange(int low, int high, int* returnSize) {
    if (high < 2) {
        *returnSize = 0;  // write through pointer
        return NULL;
    }
    bool* isPrime = (bool*)malloc((high + 1) * sizeof(bool));
    memset(isPrime, true, (high + 1) * sizeof(bool));
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= high; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= high; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int* res = (int*)malloc((high + 1) * sizeof(int));
    int count = 0;
    int start = low < 2 ? 2 : low;
    for (int i = start; i <= high; i++) {
        if (isPrime[i]) res[count++] = i;
    }

    free(isPrime);
    *returnSize = count;  // write through pointer
    return res;
}
