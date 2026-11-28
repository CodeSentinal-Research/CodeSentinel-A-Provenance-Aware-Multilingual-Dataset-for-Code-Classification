#include <stdlib.h>

typedef struct {
    int start;
    int idx;
} Pair;

int comparePairs(const void* a, const void* b) {
    return ((Pair*)a)->start - ((Pair*)b)->start;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = intervalsSize;
    Pair* starts = (Pair*)malloc(intervalsSize * sizeof(Pair));
    for (int i = 0; i < intervalsSize; i++) {
        starts[i].start = intervals[i][0];
        starts[i].idx = i;
    }
    qsort(starts, intervalsSize, sizeof(Pair), comparePairs);

    int* res = (int*)malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        int end = intervals[i][1];
        int l = 0, r = intervalsSize - 1, target = -1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (starts[mid].start >= end) {
                target = starts[mid].idx;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res[i] = target;
    }
    free(starts);
    return res;
}