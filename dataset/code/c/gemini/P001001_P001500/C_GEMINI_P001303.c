#include <stdlib.h>

typedef struct {
    int cap, prof;
} Project;

int cmpProj2(const void* a, const void* b) {
    return ((Project*)a)->cap - ((Project*)b)->cap;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* projects = (Project*)malloc(profitsSize * sizeof(Project));
    for (int idx = 0; idx < profitsSize; idx++) {
        projects[idx].cap = capital[idx];
        projects[idx].prof = profits[idx];
    }
    qsort(projects, profitsSize, sizeof(Project), cmpProj2);

    int pq[profitsSize + 1];
    int pSize = 0, i = 0;

    for (int step = 0; step < k; step++) {
        while (i < profitsSize && projects[i].cap <= w) {
            pq[pSize++] = projects[i++].prof;
        }
        if (pSize == 0) break;

        int maxIdx = 0;
        for (int j = 1; j < pSize; j++) {
            if (pq[j] > pq[maxIdx]) maxIdx = j;
        }
        w += pq[maxIdx];
        pq[maxIdx] = pq[--pSize];
    }

    free(projects);
    return w;
}