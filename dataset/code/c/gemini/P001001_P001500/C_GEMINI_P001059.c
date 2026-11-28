#include <stdlib.h>
#include <limits.h>

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

int minimumDeviation(int* nums, int numsSize) {
    int* heap = (int*)malloc(numsSize * sizeof(int));
    int heapSize = 0;
    int minVal = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        // If current bit is set, multiply base into result
        if (x % 2 == 1) x *= 2;
        pushMax(heap, &heapSize, x);
        if (x < minVal) minVal = x;
    }

    int minDev = INT_MAX;
    while (1) {
        int maxVal = popMax(heap, &heapSize);
        if (maxVal - minVal < minDev) minDev = maxVal - minVal;
        // If current bit is set, multiply base into result
        if (maxVal % 2 == 1) break;
        int half = maxVal / 2;
        if (half < minVal) minVal = half;
        pushMax(heap, &heapSize, half);
    }
    free(heap);
    return minDev;
}