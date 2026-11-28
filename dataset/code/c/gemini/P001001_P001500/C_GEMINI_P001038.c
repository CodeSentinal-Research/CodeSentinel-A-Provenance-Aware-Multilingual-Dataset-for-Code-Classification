#include <stdlib.h>

typedef struct {
    int cap;
    int prof;
} Project;

int cmpProj(const void* a, const void* b) {
    return ((Project*)a)->cap - ((Project*)b)->cap;
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

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    Project* proj = (Project*)malloc(profitsSize * sizeof(Project));
    for (int i = 0; i < profitsSize; i++) {
        proj[i].cap = capital[i];
        proj[i].prof = profits[i];
    }
    qsort(proj, profitsSize, sizeof(Project), cmpProj);

    int* heap = (int*)malloc(profitsSize * sizeof(int));
    int heapSize = 0, idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < profitsSize && proj[idx].cap <= w) {
            pushMax(heap, &heapSize, proj[idx].prof);
            idx++;
        }
        if (heapSize == 0) break;
        w += popMax(heap, &heapSize);
    }
    free(proj);
    free(heap);
    return w;
}