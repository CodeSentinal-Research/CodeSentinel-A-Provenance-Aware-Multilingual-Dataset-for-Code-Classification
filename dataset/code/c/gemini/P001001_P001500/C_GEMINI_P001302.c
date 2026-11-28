#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int s, e;
} Interval;

int cmpInterval(const void* a, const void* b) {
    return ((Interval*)a)->s - ((Interval*)b)->s;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
        for (int i = 0; i < n; i++) scanf("%d %d", &intervals[i].s, &intervals[i].e);

        qsort(intervals, n, sizeof(Interval), cmpInterval);
        int pq[n + 1];
        int pSize = 0;

        for (int i = 0; i < n; i++) {
            if (pSize > 0) {
                int minIdx = 0;
                for (int j = 1; j < pSize; j++) {
                    if (pq[j] < pq[minIdx]) minIdx = j;
                }
                if (pq[minIdx] <= intervals[i].s) {
                    pq[minIdx] = pq[--pSize];
                }
            }
            pq[pSize++] = intervals[i].e;
        }
        printf("%d\n", pSize);
        free(intervals);
    }
    return 0;
}