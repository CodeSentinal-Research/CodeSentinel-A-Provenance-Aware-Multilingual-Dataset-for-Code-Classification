#include <stdio.h>
int main() {
    int n, h; scanf("%d %d", &n, &h);
    int piles[1000]; long long max_p=0;
    for(int i=0; i<n; i++) { scanf("%d", &piles[i]); if(piles[i]>max_p) max_p=piles[i]; }
    long long l=1, r=max_p, res=max_p;
    while(l<=r) {
        long long mid = l+(r-l)/2;
        long long hours=0;
        for(int i=0; i<n; i++) hours += (piles[i]+mid-1)/mid;
        if(hours<=h) { res=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", res);
    return 0;
}
