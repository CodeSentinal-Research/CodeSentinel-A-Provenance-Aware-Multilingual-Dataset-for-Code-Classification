#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
    int* remaining = (int*)malloc(capacitySize * sizeof(int));
    for (int i = 0; i < capacitySize; i++) remaining[i] = capacity[i] - rocks[i];
    qsort(remaining, capacitySize, sizeof(int), cmpInt);

    int fullBags = 0;
    for (int i = 0; i < capacitySize; i++) {
        if (additionalRocks >= remaining[i]) {
            additionalRocks -= remaining[i];
            fullBags++;
        } else {
            break;
        }
    }
    free(remaining);
    return fullBags;
}