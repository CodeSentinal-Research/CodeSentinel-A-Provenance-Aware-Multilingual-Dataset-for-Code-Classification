#include <stdio.h>

int countFrequency(const int arr[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) count++;
    }
    return count;
}

int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%d\n", countFrequency(arr, n, target));
    }
    return 0;
}