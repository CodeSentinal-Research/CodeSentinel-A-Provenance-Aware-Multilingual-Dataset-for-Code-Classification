#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long dp[n]; dp[0] = a[0];
    int queue[n], front=0, rear=0;
    queue[rear++] = 0;
    for(int i=1; i<n; i++) {
        while(front < rear && i - queue[front] > k) front++;
        dp[i] = dp[queue[front]] + a[i];
        while(front < rear && dp[queue[rear-1]] <= dp[i]) rear--;
        queue[rear++] = i;
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
