#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    long long nums[n], prefix[n+1], queue[n+1];
    prefix[0]=0;
    for(int i=0; i<n; i++) { scanf("%lld", &nums[i]); prefix[i+1]=prefix[i]+nums[i]; }
    int front=0, rear=0, min_len=n+1;
    queue[rear++]=0;
    for(int i=1; i<=n; i++) {
        while(front<rear && prefix[i]-prefix[queue[front]]>=k) {
            min_len = i-queue[front] < min_len ? i-queue[front] : min_len;
            front++;
        }
        while(front<rear && prefix[i]<=prefix[queue[rear-1]]) rear--;
        queue[rear++]=i;
    }
    printf("%d\n", min_len>n ? -1 : min_len);
    return 0;
}
