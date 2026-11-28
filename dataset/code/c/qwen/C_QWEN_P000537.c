#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int nums[n], res[n-k+1], queue[n], front=0, rear=0;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    for(int i=0; i<n; i++) {
        while(front<rear && nums[queue[rear-1]]<=nums[i]) rear--;
        queue[rear++]=i;
        if(i-queue[front]>=k) front++;
        if(i>=k-1) res[i-k+1]=nums[queue[front]];
    }
    for(int i=0; i<n-k+1; i++) printf("%d%c", res[i], i==n-k?'\n':' ');
    return 0;
}
