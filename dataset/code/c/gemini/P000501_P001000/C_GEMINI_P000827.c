#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);
    int maxR = 0;
    int i = 0;
    for (int j = 0; j < housesSize; j++) {
        int h = houses[j];
        while (i + 1 < heatersSize && abs(heaters[i + 1] - h) <= abs(heaters[i] - h)) {
            i++;
        }
        int curDist = abs(heaters[i] - h);
        if (curDist > maxR) maxR = curDist;
    }
    return maxR;
}