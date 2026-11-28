#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int dp[n]; for(int i=0; i<n; i++) dp[i] = 1;
    int max_len = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[i] % a[j] == 0 && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        if(dp[i] > max_len) max_len = dp[i];
    }
    printf("%d\n", max_len);
    return 0;
}
