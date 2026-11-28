#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    int keys[n], freq[n];
    for(int i=0; i<n; i++) scanf("%d", &keys[i]);
    for(int i=0; i<n; i++) scanf("%d", &freq[i]);
    long long dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=0; i<n; i++) dp[i][i] = freq[i];
    for(int L=2; L<=n; L++) {
        for(int i=0; i<=n-L; i++) {
            int j = i+L-1;
            dp[i][j] = 1000000000000000000LL;
            long long sum = 0;
            for(int k=i; k<=j; k++) sum += freq[k];
            for(int k=i; k<=j; k++) {
                long long cost = (k>i ? dp[i][k-1] : 0) + (k<j ? dp[k+1][j] : 0) + sum;
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
    return 0;
}
