#include <stdio.h>
int main() {
    int n, target; scanf("%d%d", &n, &target);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=0, r=n-1, found=0;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==target) { found=1; break; }
        if(a[l]==a[mid] && a[mid]==a[r]) { l++; r--; }
        else if(a[l]<=a[mid]) { if(a[l]<=target && target<a[mid]) r=mid-1; else l=mid+1; }
        else { if(a[mid]<target && target<=a[r]) l=mid+1; else r=mid-1; }
    }
    printf("%s\n", found?"true":"false");
    return 0;
}
