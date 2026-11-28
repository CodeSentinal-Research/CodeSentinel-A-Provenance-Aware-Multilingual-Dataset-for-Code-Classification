#include <stdlib.h>

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

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize) {
    int* heap = (int*)malloc(stationsSize * sizeof(int));
    int heapSize = 0, stops = 0, curFuel = startFuel, i = 0;

    while (curFuel < target) {
        while (i < stationsSize && stations[i][0] <= curFuel) {
            pushMax(heap, &heapSize, stations[i][1]);
            i++;
        }
        if (heapSize == 0) {
            free(heap);
            return -1;
        }
        curFuel += popMax(heap, &heapSize);
        stops++;
    }
    free(heap);
    return stops;
}