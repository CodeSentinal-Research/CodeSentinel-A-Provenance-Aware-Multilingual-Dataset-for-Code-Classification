#include <stdlib.h>

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

int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int* heap = (int*)malloc(heightsSize * sizeof(int));
    int heapSize = 0;
    for (int i = 0; i < heightsSize - 1; i++) {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            pushMin(heap, &heapSize, diff);
            if (heapSize > ladders) {
                bricks -= popMin(heap, &heapSize);
                if (bricks < 0) {
                    free(heap);
                    return i;
                }
            }
        }
    }
    free(heap);
    return heightsSize - 1;
}