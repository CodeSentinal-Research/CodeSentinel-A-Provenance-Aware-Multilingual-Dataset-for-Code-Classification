#include <stdlib.h>

#define MOD 1000000007LL

typedef struct {
    int eff;
    int spd;
} Eng;

int cmpEng(const void* a, const void* b) {
    return ((Eng*)b)->eff - ((Eng*)a)->eff;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        minHeapify(arr, n, smallest);
    }
}

int popMin(int arr[], int* n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

void pushMin(int arr[], int* n, int val) {
    arr[*n] = val;
    int i = *n;
    (*n)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] < arr[p]) {
            int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
}

int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k) {
    Eng* engineers = (Eng*)malloc(n * sizeof(Eng));
    for (int i = 0; i < n; i++) {
        engineers[i].eff = efficiency[i];
        engineers[i].spd = speed[i];
    }
    qsort(engineers, n, sizeof(Eng), cmpEng);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    long long speedSum = 0, best = 0;

    for (int i = 0; i < n; i++) {
        pushMin(heap, &heapSize, engineers[i].spd);
        speedSum += engineers[i].spd;
        if (heapSize > k) {
            speedSum -= popMin(heap, &heapSize);
        }
        long long cur = speedSum * engineers[i].eff;
        if (cur > best) best = cur;
    }
    free(engineers);
    free(heap);
    return (int)(best % MOD);
}