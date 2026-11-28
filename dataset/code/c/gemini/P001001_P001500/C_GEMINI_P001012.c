#include <stdio.h>
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

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int total = n + m;
        int* merged = (int*)malloc(total * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &merged[i]);
        for (int i = 0; i < m; i++) scanf("%d", &merged[n + i]);
        for (int i = total / 2 - 1; i >= 0; i--) {
            minHeapify(merged, total, i);
        }
        for (int i = 0; i < total; i++) {
            printf("%d%s", merged[i], (i == total - 1 ? "" : " "));
        }
        printf("\n");
        free(merged);
    }
    return 0;
}