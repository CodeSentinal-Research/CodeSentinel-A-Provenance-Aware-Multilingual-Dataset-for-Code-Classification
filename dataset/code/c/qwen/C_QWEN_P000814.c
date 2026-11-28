#include <stdio.h>
int main() {
    int n, bad; scanf("%d%d", &n, &bad);
    int l=1, r=n, ans=bad;
    while(l<=r) { int mid=l+(r-l)/2; if(mid>=bad) { ans=mid; r=mid-1; } else l=mid+1; }
    printf("%d\n", ans);
    return 0;
}
