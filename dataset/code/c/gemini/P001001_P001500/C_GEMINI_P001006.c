#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(const int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[i] > arr[left]) return false;
        if (right < n && arr[i] > arr[right]) return false;
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%s\n", isMinHeap(arr, n) ? "YES" : "NO");
    }
    return 0;
}