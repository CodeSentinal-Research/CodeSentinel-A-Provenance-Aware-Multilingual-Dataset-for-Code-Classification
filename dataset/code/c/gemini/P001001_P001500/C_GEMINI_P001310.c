#include <stdio.h>
#include <stdlib.h>

void minHeapify(long long heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        long long t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        minHeapify(heap, n, smallest);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long* heap = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &heap[i]);

        for (int i = n / 2 - 1; i >= 0; i--) minHeapify(heap, n, i);

        long long totalCost = 0;
        int size = n;
        while (size > 1) {
            long long s1 = heap[0];
            heap[0] = heap[size - 1];
            size--;
            minHeapify(heap, size, 0);

            long long s2 = heap[0];
            long long cost = s1 + s2;
            totalCost += cost;

            heap[0] = cost;
            minHeapify(heap, size, 0);
        }
        printf("%lld\n", totalCost);
        free(heap);
    }
    return 0;
}