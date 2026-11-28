#include <stdlib.h>

int cmpPair(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return p1[1] - p2[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), cmpPair);
    int cur = -1000000000, ans = 0;
    for (int i = 0; i < pairsSize; i++) {
        if (cur < pairs[i][0]) {
            cur = pairs[i][1];
            ans++;
        }
    }
    return ans;
}