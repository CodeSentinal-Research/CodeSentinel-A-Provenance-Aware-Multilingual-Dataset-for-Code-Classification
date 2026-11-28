#include <stdlib.h>
#include <limits.h>

struct Activity {
    int start;
    int end;
};

int cmpAct(const void* a, const void* b) {
    return ((struct Activity*)a)->end - ((struct Activity*)b)->end;
}

int activitySelection(int* start, int* end, int n) {
    struct Activity* act = (struct Activity*)malloc(n * sizeof(struct Activity));
    for (int i = 0; i < n; i++) {
        act[i].start = start[i];
        act[i].end = end[i];
    }
    qsort(act, n, sizeof(struct Activity), cmpAct);

    int count = 0, lastEnd = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (act[i].start > lastEnd) {
            count++;
            lastEnd = act[i].end;
        }
    }
    free(act);
    return count;
}