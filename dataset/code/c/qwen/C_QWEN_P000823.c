#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=1, r=a[n-1]+k, ans=0;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int missing = mid - (int)(lower_bound(a, n, mid));
        if(missing < k) l=mid+1; else { ans=mid; r=mid-1; }
    }
    printf("%d\n", ans);
    return 0;
}
