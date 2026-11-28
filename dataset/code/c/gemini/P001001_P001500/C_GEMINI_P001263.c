#include <stdlib.h>

int cmpCost(const void* a, const void* b) {
    int* c1 = *(int**)a;
    int* c2 = *(int**)b;
    return (c1[0] - c1[1]) - (c2[0] - c2[1]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    qsort(costs, costsSize, sizeof(int*), cmpCost);
    int n = costsSize / 2;
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += costs[i][0] + costs[i + n][1];
    }
    return total;
}