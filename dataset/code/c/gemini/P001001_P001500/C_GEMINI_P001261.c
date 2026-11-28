#include <stdlib.h>

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize) {
    long long cur = startFuel;
    int stops = 0, i = 0;
    int pq[stationsSize + 1];
    int pSize = 0;

    while (cur < target) {
        while (i < stationsSize && stations[i][0] <= cur) {
            pq[pSize++] = stations[i++][1];
        }
        if (pSize == 0) return -1;

        // find max
        int maxIdx = 0;
        for (int j = 1; j < pSize; j++) {
            if (pq[j] > pq[maxIdx]) maxIdx = j;
        }
        cur += pq[maxIdx];
        pq[maxIdx] = pq[--pSize];
        stops++;
    }
    return stops;
}