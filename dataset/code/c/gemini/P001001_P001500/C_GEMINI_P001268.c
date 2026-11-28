#include <stdlib.h>

int cmpEvents(const void* a, const void* b) {
    int* e1 = *(int**)a;
    int* e2 = *(int**)b;
    return e1[0] - e2[0];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    qsort(events, eventsSize, sizeof(int*), cmpEvents);
    int pq[eventsSize + 1];
    int pSize = 0;
    int day = 0, count = 0, i = 0;

    while (i < eventsSize || pSize > 0) {
        if (pSize == 0) {
            day = events[i][0];
        }
        while (i < eventsSize && events[i][0] <= day) {
            pq[pSize++] = events[i++][1];
        }

        // find min end day
        int minIdx = 0;
        for (int j = 1; j < pSize; j++) {
            if (pq[j] < pq[minIdx]) minIdx = j;
        }
        pq[minIdx] = pq[--pSize];
        count++;
        day++;

        // remove expired
        int writeIdx = 0;
        for (int j = 0; j < pSize; j++) {
            if (pq[j] >= day) {
                pq[writeIdx++] = pq[j];
            }
        }
        pSize = writeIdx;
    }
    return count;
}