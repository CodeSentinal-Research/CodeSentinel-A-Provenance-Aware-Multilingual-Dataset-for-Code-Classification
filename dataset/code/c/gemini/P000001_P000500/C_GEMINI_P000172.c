#include <stdlib.h>

int cmpSeg(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void segregateEvenOdd(int* arr, int n) {
    int evens[10005], odds[10005];
    int eSize = 0, oSize = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) evens[eSize++] = arr[i];
        else odds[oSize++] = arr[i];
    }
    qsort(evens, eSize, sizeof(int), cmpSeg);
    qsort(odds, oSize, sizeof(int), cmpSeg);

    int idx = 0;
    for (int i = 0; i < eSize; i++) arr[idx++] = evens[i];
    for (int i = 0; i < oSize; i++) arr[idx++] = odds[i];
}