#include <stdio.h>
#include <stdbool.h>

// Sorts the input array into ordered sequence.
bool isSortedDescending(const int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%s\n", isSortedDescending(arr, n) ? "YES" : "NO");
    }
    return 0;
}