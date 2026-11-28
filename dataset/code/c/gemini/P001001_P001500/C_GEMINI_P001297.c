#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long* arr = (long long*)malloc(n * sizeof(long long));
        long long baseSum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            baseSum += (long long)i * arr[i];
        }

        long long maxSum = baseSum;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long gain = (long long)(j - i) * arr[i] + (long long)(i - j) * arr[j];
                maxSum = MAX(maxSum, baseSum + gain);
            }
        }
        printf("%lld\n", maxSum);
        free(arr);
    }
    return 0;
}