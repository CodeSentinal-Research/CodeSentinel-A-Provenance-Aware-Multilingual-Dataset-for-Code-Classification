#include <stdio.h>
#include <string.h>
int dp[50001][4];
int solve(int *a, int i, int n) {
    if(i >= n) return 0;
    if(dp[i][1] != -1) return dp[i][1]; // simplified
    int sum1 = a[i] + (solve(a, i+1, n) > solve(a, i+2, n) ? solve(a, i+1, n) : solve(a, i+2, n)); // simplified logic
    // Actually standard DP
    int s1=0, s2=0, s3=0;
    if(i<n) s1 = a[i] + (i+3<n ? solve(a, i+3, n) : 0);
    if(i+1<n) s2 = a[i] + a[i+1] + (i+4<n ? solve(a, i+4, n) : 0);
    if(i+2<n) s3 = a[i] + a[i+1] + a[i+2] + (i+5<n ? solve(a, i+5, n) : 0);
    int mx = s1; if(s2>mx) mx=s2; if(s3>mx) mx=s3;
    return dp[i][1] = mx;
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; long long sum=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    memset(dp, -1, sizeof(dp));
    int alice = solve(a, 0, n);
    if(alice > sum - alice) printf("Alice\n");
    else if(alice < sum - alice) printf("Bob\n");
    else printf("Tie\n");
    return 0;
}
