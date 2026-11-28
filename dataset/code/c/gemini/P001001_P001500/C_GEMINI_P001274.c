#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxIceCream(int* costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), cmpInt);
    int count = 0;
    for (int i = 0; i < costsSize; i++) {
        if (coins >= costs[i]) {
            coins -= costs[i];
            count++;
        } else {
            break;
        }
    }
    return count;
}