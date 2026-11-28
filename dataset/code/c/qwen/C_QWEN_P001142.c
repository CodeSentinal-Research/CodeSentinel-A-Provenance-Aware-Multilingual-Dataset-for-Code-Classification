#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; long long sum = 0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    if(sum % 2 != 0) { printf("NO\n"); return 0; }
    int target = sum / 2;
    int dp[target+1]; for(int i=0; i<=target; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=0; i<n; i++) for(int j=target; j>=a[i]; j--) dp[j] = dp[j] || dp[j-a[i]];
    printf("%s\n", dp[target] ? "YES" : "NO");
    return 0;
}
