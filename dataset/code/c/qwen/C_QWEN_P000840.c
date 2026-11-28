#include <stdio.h>
int main() {
    int n, maxOps; scanf("%d%d", &n, &maxOps);
    int a[n]; long long max_a=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); if(a[i]>max_a) max_a=a[i]; }
    long long l=1, r=max_a, ans=max_a;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long ops=0;
        for(int i=0; i<n; i++) ops += (a[i]-1)/mid;
        if(ops<=maxOps) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
