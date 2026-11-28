#include <stdio.h>

long long countEqualPosNegSubarrays(const int arr[], int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int pos = 0, neg = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] > 0) pos++;
            else if (arr[j] < 0) neg++;
            if (pos == neg) count++;
        }
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%lld\n", countEqualPosNegSubarrays(arr, n));
    }
    return 0;
}