#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int xorSum = 0;
            for (int j = i; j < n; j++) {
                xorSum ^= arr[j];
                if (xorSum == 0) ans++;
            }
        }
        printf("%lld\n", ans);
        free(arr);
    }
    return 0;
}