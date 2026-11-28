#include <stdio.h>
int main() {
    int n, target; scanf("%d%d", &n, &target);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=0, r=n;
    while(l<r) { int mid=l+(r-l)/2; if(a[mid]<target) l=mid+1; else r=mid; }
    printf("%d\n", l);
    return 0;
}
