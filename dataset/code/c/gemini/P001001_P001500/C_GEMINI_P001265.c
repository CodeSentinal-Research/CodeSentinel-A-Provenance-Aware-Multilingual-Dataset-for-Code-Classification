#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MOD 1000000007LL

typedef struct {
    int eff, spd;
} Eng;

int cmpEng(const void* a, const void* b) {
    return ((Eng*)b)->eff - ((Eng*)a)->eff;
}

int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k) {
    Eng* engineers = (Eng*)malloc(n * sizeof(Eng));
    for (int i = 0; i < n; i++) {
        engineers[i].eff = efficiency[i];
        engineers[i].spd = speed[i];
    }
    qsort(engineers, n, sizeof(Eng), cmpEng);

    int pq[k + 2];
    int pSize = 0;
    long long speedSum = 0, maxPerf = 0;

    for (int i = 0; i < n; i++) {
        int eff = engineers[i].eff, spd = engineers[i].spd;
        pq[pSize++] = spd;
        speedSum += spd;

        if (pSize > k) {
            int minIdx = 0;
            for (int j = 1; j < pSize; j++) {
                if (pq[j] < pq[minIdx]) minIdx = j;
            }
            speedSum -= pq[minIdx];
            pq[minIdx] = pq[--pSize];
        }

        long long perf = speedSum * eff;
        if (perf > maxPerf) maxPerf = perf;
    }

    free(engineers);
    return (int)(maxPerf % MOD);
}