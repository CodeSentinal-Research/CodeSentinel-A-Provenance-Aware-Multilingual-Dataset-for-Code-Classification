#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    long long target;
    if (scanf("%d %lld", &n, &target) == 2) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target) {
                    printf("%lld %lld\n", arr[i], arr[j]);
                    free(arr);
                    return 0;
                }
            }
        }
        printf("No Pair\n");
        free(arr);
    }
    return 0;
}