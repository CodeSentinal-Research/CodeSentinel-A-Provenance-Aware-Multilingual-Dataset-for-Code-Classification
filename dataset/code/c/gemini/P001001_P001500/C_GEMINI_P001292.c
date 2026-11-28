#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    int* arrival = (int*)malloc(distSize * sizeof(int));
    for (int i = 0; i < distSize; i++) {
        arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
    }
    qsort(arrival, distSize, sizeof(int), cmpInt);

    for (int minute = 0; minute < distSize; minute++) {
        if (minute >= arrival[minute]) {
            free(arrival);
            return minute;
        }
    }
    free(arrival);
    return distSize;
}