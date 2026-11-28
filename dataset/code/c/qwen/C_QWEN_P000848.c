#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n], total=0, max_a=0;
    for(int i=0; i<n; i++) { scanf("%lld", &a[i]); total+=a[i]; if(a[i]>max_a) max_a=a[i]; }
    long long l=(total+n-1)/n, r=max_a, ans=max_a;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, ok=1;
        for(int i=0; i<n; i++) {
            sum+=a[i];
            if(sum > mid*(i+1)) { ok=0; break; }
        }
        if(ok) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
