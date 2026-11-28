#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; long long total=0, max_a=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); total+=a[i]; if(a[i]>max_a) max_a=a[i]; }
    long long l=max_a, r=total, ans=total;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, parts=1;
        for(int i=0; i<n; i++) { if(sum+a[i]>mid) { parts++; sum=a[i]; } else sum+=a[i]; }
        if(parts<=k) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
