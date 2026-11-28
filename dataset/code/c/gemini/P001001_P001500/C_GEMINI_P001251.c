#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpBox(const void* a, const void* b) {
    int* b1 = *(int**)a;
    int* b2 = *(int**)b;
    return b2[1] - b1[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    qsort(boxTypes, boxTypesSize, sizeof(int*), cmpBox);
    int totalUnits = 0;

    for (int i = 0; i < boxTypesSize; i++) {
        int take = MIN(truckSize, boxTypes[i][0]);
        totalUnits += take * boxTypes[i][1];
        truckSize -= take;
        if (truckSize == 0) break;
    }
    return totalUnits;
}