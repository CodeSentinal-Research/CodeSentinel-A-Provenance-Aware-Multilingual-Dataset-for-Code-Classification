#include <stdlib.h>
#include <float.h>

typedef struct {
    double ratio;
    int quality;
} Worker;

int cmpWorker(const void* a, const void* b) {
    double r1 = ((Worker*)a)->ratio;
    double r2 = ((Worker*)b)->ratio;
    if (r1 < r2) return -1;
    if (r1 > r2) return 1;
    return 0;
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
    Worker* workers = (Worker*)malloc(qualitySize * sizeof(Worker));
    for (int i = 0; i < qualitySize; i++) {
        workers[i].ratio = (double)wage[i] / quality[i];
        workers[i].quality = quality[i];
    }
    qsort(workers, qualitySize, sizeof(Worker), cmpWorker);

    int pq[k + 2];
    int pSize = 0;
    double qualSum = 0, minCost = DBL_MAX;

    for (int i = 0; i < qualitySize; i++) {
        double ratio = workers[i].ratio;
        int q = workers[i].quality;
        pq[pSize++] = q;
        qualSum += q;

        if (pSize > k) {
            int maxIdx = 0;
            for (int j = 1; j < pSize; j++) {
                if (pq[j] > pq[maxIdx]) maxIdx = j;
            }
            qualSum -= pq[maxIdx];
            pq[maxIdx] = pq[--pSize];
        }

        if (pSize == k) {
            double cost = qualSum * ratio;
            if (cost < minCost) minCost = cost;
        }
    }
    free(workers);
    return minCost;
}