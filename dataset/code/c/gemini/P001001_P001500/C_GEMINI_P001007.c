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

void replaceRoot(int arr[], int n, int x) {
    arr[0] = x;
    maxHeapify(arr, n, 0);
}

int main() {
    int n, x;
    if (scanf("%d %d", &n, &x) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        replaceRoot(arr, n, x);
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}