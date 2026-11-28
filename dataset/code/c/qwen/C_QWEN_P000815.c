#include <stdio.h>
int main() {
    int n, target; scanf("%d%d", &n, &target);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=0, r=n-1, first=-1, last=-1;
    while(l<=r) { int mid=l+(r-l)/2; if(a[mid]==target) { first=mid; r=mid-1; } else if(a[mid]<target) l=mid+1; else r=mid-1; }
    l=0; r=n-1;
    while(l<=r) { int mid=l+(r-l)/2; if(a[mid]==target) { last=mid; l=mid+1; } else if(a[mid]<target) l=mid+1; else r=mid-1; }
    printf("%d %d\n", first, last);
    return 0;
}
