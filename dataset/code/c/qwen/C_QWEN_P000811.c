#include <stdio.h>
int main() {
    int n, target; scanf("%d%d", &n, &target);
    int l=1, r=n, ans=target;
    while(l<=r) { int mid=l+(r-l)/2; if(mid==target) { ans=mid; break; } else if(mid<target) l=mid+1; else r=mid-1; }
    printf("%d\n", ans);
    return 0;
}
