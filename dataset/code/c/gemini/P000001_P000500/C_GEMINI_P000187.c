#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        long long val = 1;
        while (1) {
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == val) { found = 1; break; }
            }
            if (!found) break;
            val++;
        }
        printf("%lld\n", val);
        free(arr);
    }
    return 0;
}