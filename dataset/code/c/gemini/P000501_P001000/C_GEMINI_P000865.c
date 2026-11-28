#include <stdio.h>

int xorAll(const int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) ans ^= arr[i];
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%d\n", xorAll(arr, n));
    }
    return 0;
}