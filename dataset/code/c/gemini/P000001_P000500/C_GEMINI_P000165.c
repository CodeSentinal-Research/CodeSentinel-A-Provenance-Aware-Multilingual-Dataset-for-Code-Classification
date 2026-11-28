#include <stdio.h>
#include <stdlib.h>
long long max_ll(long long a, long long b) { return a > b ? a : b; }
long long min_ll(long long a, long long b) { return a < b ? a : b; }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        long long max_p = arr[0], min_p = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                long long t = max_p; max_p = min_p; min_p = t;
            }
            max_p = max_ll(arr[i], max_p * arr[i]);
            min_p = min_ll(arr[i], min_p * arr[i]);
            ans = max_ll(ans, max_p);
        }
        printf("%lld\n", ans);
        free(arr);
    }
    return 0;
}