#include <stdio.h>
#include <string.h>
int dp[1001][1001];
int solve(int *piles, int i, int m, int n, int sum) {
    if(i >= n) return 0;
    if(dp[i][m] != -1) return dp[i][m];
    int max_stones = 0;
    for(int x=1; x<=2*m && i+x<=n; x++) {
        int next_m = x > m ? x : m;
        int stones = 0; for(int k=i; k<i+x; k++) stones += piles[k];
        int val = stones + sum - solve(piles, i+x, next_m, n, sum);
        if(val > max_stones) max_stones = val;
    }
    return dp[i][m] = max_stones;
}
int main() {
    int n; scanf("%d", &n);
    int piles[n]; int sum = 0;
    for(int i=0; i<n; i++) { scanf("%d", &piles[i]); sum += piles[i]; }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(piles, 0, 1, n, sum));
    return 0;
}
