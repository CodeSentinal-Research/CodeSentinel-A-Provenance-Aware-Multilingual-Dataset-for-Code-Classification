#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n); int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int dp[n], parent[n];
    for(int i=0; i<n; i++) { dp[i] = 1; parent[i] = -1; }
    int max_len = 1, max_idx = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[i] % a[j] == 0 && dp[j] + 1 > dp[i]) { dp[i] = dp[j] + 1; parent[i] = j; }
        }
        if(dp[i] > max_len) { max_len = dp[i]; max_idx = i; }
    }
    int res[n], idx = 0;
    while(max_idx != -1) { res[idx++] = a[max_idx]; max_idx = parent[max_idx]; }
    for(int i=idx-1; i>=0; i--) printf("%d%c", res[i], i==0?'\n':' ');
    return 0;
}
