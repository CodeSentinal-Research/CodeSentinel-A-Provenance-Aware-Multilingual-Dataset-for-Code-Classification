#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    long long bat[m], total=0;
    for(int i=0; i<m; i++) { scanf("%lld", &bat[i]); total+=bat[i]; }
    long long l=0, r=total/n, ans=0;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<m; i++) sum += bat[i]<mid?bat[i]:mid;
        if(sum>=n*mid) { ans=mid; l=mid+1; } else r=mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}
