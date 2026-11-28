#include <stdio.h>

int maxLenEqualEvenOdd(const int arr[], int n) {
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int even = 0, odd = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] % 2 == 0) even++;
            else odd++;
            if (even == odd && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
            }
        }
    }
    return maxLen;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%d\n", maxLenEqualEvenOdd(arr, n));
    }
    return 0;
}