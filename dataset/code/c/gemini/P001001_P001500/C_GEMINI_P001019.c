#include <stdlib.h>

int cmpPoints(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    long long d1 = (long long)p1[0]*p1[0] + (long long)p1[1]*p1[1];
    long long d2 = (long long)p2[0]*p2[0] + (long long)p2[1]*p2[1];
    return (d1 > d2) - (d1 < d2);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(points, pointsSize, sizeof(int*), cmpPoints);
    *returnSize = k;
    *returnColumnSizes = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) (*returnColumnSizes)[i] = 2;
    return points;
}