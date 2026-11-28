#include <stdio.h>
int main() {
    int n, painters; scanf("%d%d", &n, &painters);
    int boards[n]; long long total=0, max_b=0;
    for(int i=0; i<n; i++) { scanf("%d", &boards[i]); total+=boards[i]; if(boards[i]>max_b) max_b=boards[i]; }
    long long l=max_b, r=total, ans=total;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, p=1;
        for(int i=0; i<n; i++) { if(sum+boards[i]>mid) { p++; sum=boards[i]; } else sum+=boards[i]; }
        if(p<=painters) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
