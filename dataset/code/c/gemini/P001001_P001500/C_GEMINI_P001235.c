#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int deadline, profit;
} Job;

int cmpJob(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        Job* jobs = (Job*)malloc(n * sizeof(Job));
        int maxD = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &jobs[i].deadline);
            if (jobs[i].deadline > maxD) maxD = jobs[i].deadline;
        }
        for (int i = 0; i < n; i++) scanf("%d", &jobs[i].profit);

        qsort(jobs, n, sizeof(Job), cmpJob);
        int* slots = (int*)malloc((maxD + 1) * sizeof(int));
        memset(slots, -1, (maxD + 1) * sizeof(int));

        int count = 0, totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = jobs[i].profit;
                    count++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }
        printf("%d %d\n", count, totalProfit);
        free(jobs);
        free(slots);
    }
    return 0;
}