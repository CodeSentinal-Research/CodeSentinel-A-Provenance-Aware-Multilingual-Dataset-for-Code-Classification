#include <stdio.h>
#include <stdlib.h>
long long max_ll(long long a, long long b) { return a > b ? a : b; }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        long long max_so_far = arr[0], curr_max = arr[0];
        for (int i = 1; i < n; i++) {
            curr_max = max_ll(arr[i], curr_max + arr[i]);
            max_so_far = max_ll(max_so_far, curr_max);
        }
        printf("%lld\n", max_so_far);
        free(arr);
    }
    return 0;
}