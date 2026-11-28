#include <stdlib.h>

int cmpInterval(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if (p1[1] < p2[1]) return -1;
    if (p1[1] > p2[1]) return 1;
    return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmpInterval);

    int count = 0;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < lastEnd) {
            count++;
        } else {
            lastEnd = intervals[i][1];
        }
    }
    return count;
}