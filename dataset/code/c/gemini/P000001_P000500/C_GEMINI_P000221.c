#include <stdlib.h>
#include <limits.h>

int cmpPairsChain(const void* a, const void* b) {
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), cmpPairsChain);
    int curEnd = INT_MIN;
    int chain = 0;

    for (int i = 0; i < pairsSize; i++) {
        if (pairs[i][0] > curEnd) {
            chain++;
            curEnd = pairs[i][1];
        }
    }
    return chain;
}