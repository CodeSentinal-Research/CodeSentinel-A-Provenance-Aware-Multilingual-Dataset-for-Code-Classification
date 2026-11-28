#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dp[n], count[n];
    for(int i=0; i<n; i++) { dp[i] = 1; count[i] = 1; }
    int max_len = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(dp[j] + 1 > dp[i]) { dp[i] = dp[j] + 1; count[i] = count[j]; }
                else if(dp[j] + 1 == dp[i]) count[i] += count[j];
            }
        }
        if(dp[i] > max_len) max_len = dp[i];
    }
    int total = 0;
    for(int i=0; i<n; i++) if(dp[i] == max_len) total += count[i];
    printf("%d\n", total);
    return 0;
}
