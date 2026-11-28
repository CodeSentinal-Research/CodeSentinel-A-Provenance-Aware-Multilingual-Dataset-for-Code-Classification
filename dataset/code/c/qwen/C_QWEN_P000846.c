#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int q[m]; long long total=0, max_q=0;
    for(int i=0; i<m; i++) { scanf("%d", &q[i]); total+=q[i]; if(q[i]>max_q) max_q=q[i]; }
    long long l=1, r=max_q, ans=max_q;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long stores=0;
        for(int i=0; i<m; i++) stores += (q[i]+mid-1)/mid;
        if(stores<=n) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
