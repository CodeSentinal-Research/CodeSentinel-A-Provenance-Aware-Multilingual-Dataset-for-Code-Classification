#include <stdio.h>

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
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}