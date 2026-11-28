#include <stdio.h>
#include <stdlib.h>

void minHeapify(long long arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        long long t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        minHeapify(arr, n, smallest);
    }
}

long long popMin(long long arr[], int* n) {
    long long root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

void pushMin(long long arr[], int* n, long long val) {
    arr[*n] = val;
    int i = *n;
    (*n)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] < arr[p]) {
            long long t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        long long* arr = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
        long long total = 0;
        int size = n;
        while (size > 1) {
            long long a = popMin(arr, &size);
            long long b = popMin(arr, &size);
            long long cost = a + b;
            total += cost;
            pushMin(arr, &size, cost);
        }
        printf("%lld\n", total);
        free(arr);
    }
    return 0;
}