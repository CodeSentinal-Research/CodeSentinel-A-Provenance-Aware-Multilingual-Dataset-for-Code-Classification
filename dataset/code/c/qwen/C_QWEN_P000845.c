#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; long long max_a=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); if(a[i]>max_a) max_a=a[i]; }
    long long l=0, r=max_a, ans=max_a;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        int count=0;
        for(int i=0; i<n; i++) { if(a[i]<=mid) { count++; i++; } }
        if(count>=k) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
