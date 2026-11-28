#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        maxHeapify(arr, n, largest);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        if (n > 1) {
            arr[0] = arr[n - 1];
            maxHeapify(arr, n - 1, 0);
        }
        for (int i = 0; i < n - 1; i++) {
            printf("%d%s", arr[i], (i == n - 2 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}