#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int nums[n]; long long dp[n];
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    int queue[n], front=0, rear=0;
    dp[0]=nums[0]; queue[rear++]=0;
    for(int i=1; i<n; i++) {
        while(front<rear && i-queue[front]>k) front++;
        dp[i] = dp[queue[front]] + nums[i];
        while(front<rear && dp[queue[rear-1]]<=dp[i]) rear--;
        queue[rear++]=i;
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
