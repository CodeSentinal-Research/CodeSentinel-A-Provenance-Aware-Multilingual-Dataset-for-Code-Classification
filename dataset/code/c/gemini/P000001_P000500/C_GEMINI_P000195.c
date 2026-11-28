#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        printf("%lld", arr[n - 1]);
        for (int i = 0; i < n - 1; i++) printf(" %lld", arr[i]);
        printf("\n");
        free(arr);
    }
    return 0;
}