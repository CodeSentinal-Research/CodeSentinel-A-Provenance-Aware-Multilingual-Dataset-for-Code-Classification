#include <stdio.h>
int main() {
    int n, threshold; scanf("%d%d", &n, &threshold);
    int a[n]; long long max_a=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); if(a[i]>max_a) max_a=a[i]; }
    long long l=1, r=max_a, ans=max_a;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<n; i++) sum += (a[i]+mid-1)/mid;
        if(sum<=threshold) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
