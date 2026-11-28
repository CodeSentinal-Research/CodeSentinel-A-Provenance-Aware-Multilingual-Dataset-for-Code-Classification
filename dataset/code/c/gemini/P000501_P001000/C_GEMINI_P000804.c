#include <stdio.h>

long long countSubarraysXorK(const int arr[], int n, int k) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int curXor = 0;
        for (int j = i; j < n; j++) {
            curXor ^= arr[j];
            if (curXor == k) count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%lld\n", countSubarraysXorK(arr, n, k));
    }
    return 0;
}