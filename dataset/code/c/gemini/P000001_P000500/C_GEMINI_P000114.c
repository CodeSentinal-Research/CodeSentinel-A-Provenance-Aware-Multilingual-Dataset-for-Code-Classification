#include <stdio.h>

void reverse(int arr[], int l, int r) {
    while (l < r) {
        int tmp = arr[l];
        arr[l++] = arr[r];
        arr[r--] = tmp;
    }
}

void rotateLeft(int arr[], int n, int k) {
    if (n <= 0) return;
    k = k % n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        rotateLeft(arr, n, k);
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}