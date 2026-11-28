#include <stdlib.h>
#include <float.h>

typedef struct {
    double ratio;
    int q;
} Worker;

int cmpWorkers(const void* a, const void* b) {
    double r1 = ((Worker*)a)->ratio;
    double r2 = ((Worker*)b)->ratio;
    return (r1 > r2) - (r1 < r2);
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        maxHeapify(arr, n, largest);
    }
}

int popMax(int arr[], int* n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
    return root;
}

void pushMax(int arr[], int* n, int val) {
    arr[*n] = val;
    int i = *n;
    (*n)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] > arr[p]) {
            int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
    Worker* workers = (Worker*)malloc(qualitySize * sizeof(Worker));
    for (int i = 0; i < qualitySize; i++) {
        workers[i].ratio = (double)wage[i] / quality[i];
        workers[i].q = quality[i];
    }
    qsort(workers, qualitySize, sizeof(Worker), cmpWorkers);

    int* heap = (int*)malloc(qualitySize * sizeof(int));
    int heapSize = 0;
    double qSum = 0, ans = DBL_MAX;

    for (int i = 0; i < qualitySize; i++) {
        pushMax(heap, &heapSize, workers[i].q);
        qSum += workers[i].q;
        if (heapSize > k) {
            qSum -= popMax(heap, &heapSize);
        }
        if (heapSize == k) {
            double cost = qSum * workers[i].ratio;
            if (cost < ans) ans = cost;
        }
    }
    free(workers);
    free(heap);
    return ans;
}