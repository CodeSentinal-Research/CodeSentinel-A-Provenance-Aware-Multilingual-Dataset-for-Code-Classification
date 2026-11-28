#include <stdio.h>
int main() {
    int n, d; scanf("%d %d", &n, &d);
    int weights[1000]; long long total=0, max_w=0;
    for(int i=0; i<n; i++) { scanf("%d", &weights[i]); total+=weights[i]; if(weights[i]>max_w) max_w=weights[i]; }
    long long l=max_w, r=total, res=total;
    while(l<=r) {
        long long mid = l+(r-l)/2;
        long long sum=0, days=1;
        for(int i=0; i<n; i++) {
            if(sum+weights[i]>mid) { days++; sum=weights[i]; }
            else sum+=weights[i];
        }
        if(days<=d) { res=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", res);
    return 0;
}
