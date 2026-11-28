#include <stdio.h>

int main() {
    int n; long long k; scanf("%d %lld", &n, &k);
    long long arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); prefix[i+1] = prefix[i] + arr[i]; }
    
    int min_len = n + 1;
    int dq[n+1], front=0, rear=0;
    dq[rear++] = 0;
    
    for(int i=1; i<=n; i++) {
        while(front < rear && prefix[i] - prefix[dq[front]] >= k) {
            if(i - dq[front] < min_len) min_len = i - dq[front];
            front++;
        }
        while(front < rear && prefix[i] <= prefix[dq[rear-1]]) rear--;
        dq[rear++] = i;
    }
    printf("%d\n", min_len > n ? -1 : min_len);
    return 0;
}
