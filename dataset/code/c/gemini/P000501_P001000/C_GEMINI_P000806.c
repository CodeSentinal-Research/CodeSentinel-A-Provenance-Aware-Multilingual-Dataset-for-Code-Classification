#include <stdio.h>

int maxLenEqualPosNeg(const int arr[], int n) {
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int pos = 0, neg = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] > 0) pos++;
            else if (arr[j] < 0) neg++;
            if (pos == neg && (j - i + 1) > maxLen) {
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
        printf("%d\n", maxLenEqualPosNeg(arr, n));
    }
    return 0;
}