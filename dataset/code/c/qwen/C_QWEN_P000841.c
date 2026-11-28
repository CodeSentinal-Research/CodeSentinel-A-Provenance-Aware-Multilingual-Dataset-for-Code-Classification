#include <stdio.h>
int main() {
    int n; long long k; scanf("%d%lld", &n, &k);
    long long a[n], total=0;
    for(int i=0; i<n; i++) { scanf("%lld", &a[i]); total+=a[i]; }
    long long l=0, r=total/k, ans=0;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long count=0;
        for(int i=0; i<n; i++) count += a[i]/mid;
        if(count>=k) { ans=mid; l=mid+1; } else r=mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}
