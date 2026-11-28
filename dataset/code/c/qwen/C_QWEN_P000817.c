#include <stdio.h>
int main() {
    int n, target; scanf("%d%d", &n, &target);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=0, r=n-1, idx=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==target) { idx=mid; break; }
        if(a[l]<=a[mid]) { if(a[l]<=target && target<a[mid]) r=mid-1; else l=mid+1; }
        else { if(a[mid]<target && target<=a[r]) l=mid+1; else r=mid-1; }
    }
    printf("%d\n", idx);
    return 0;
}
