#include <stdio.h>

int findMinInMaxHeap(const int arr[], int n) {
    int leafStart = n / 2;
    int minVal = arr[leafStart];
    for (int i = leafStart + 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%d\n", findMinInMaxHeap(arr, n));
    }
    return 0;
}