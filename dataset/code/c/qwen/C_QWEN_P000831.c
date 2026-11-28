#include <stdio.h>
int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int bloom[n]; long long max_d=0;
    for(int i=0; i<n; i++) { scanf("%d", &bloom[i]); if(bloom[i]>max_d) max_d=bloom[i]; }
    long long l=1, r=max_d, ans=-1;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        int bouquets=0, flowers=0;
        for(int i=0; i<n; i++) {
            if(bloom[i]<=mid) { flowers++; if(flowers==k) { bouquets++; flowers=0; } }
            else flowers=0;
        }
        if(bouquets>=m) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
