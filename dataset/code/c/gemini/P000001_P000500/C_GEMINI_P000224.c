#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int cmpJob(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int* JobScheduling(struct Job arr[], int n, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    qsort(arr, n, sizeof(struct Job), cmpJob);

    int maxD = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxD) maxD = arr[i].deadline;
    }

    int* slot = (int*)malloc((maxD + 1) * sizeof(int));
    for (int i = 0; i <= maxD; i++) slot[i] = -1;

    int count = 0, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int d = arr[i].deadline; d > 0; d--) {
            if (slot[d] == -1) {
                slot[d] = arr[i].id;
                count++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    res[0] = count;
    res[1] = totalProfit;
    free(slot);
    return res;
}