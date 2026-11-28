#include <stdio.h>
int main() {
    int m, n; scanf("%d%d", &m, &n);
    int nums1[m], nums2[n];
    for(int i=0; i<m; i++) scanf("%d", &nums1[i]);
    for(int i=0; i<n; i++) scanf("%d", &nums2[i]);
    if(m>n) { int t=m; m=n; n=t; int *p=nums1; nums1=nums2; nums2=p; }
    int l=0, r=m;
    while(l<=r) {
        int mid1=l+(r-l)/2, mid2=(m+n+1)/2-mid1;
        int l1 = mid1==0?-2147483647:nums1[mid1-1], r1 = mid1==m?2147483647:nums1[mid1];
        int l2 = mid2==0?-2147483647:nums2[mid2-1], r2 = mid2==n?2147483647:nums2[mid2];
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2==0) printf("%.1f\n", ((l1>r1?l1:r1) + (l2>r2?l2:r2))/2.0);
            else printf("%.1f\n", (l1>l2?l1:l2)*1.0);
            return 0;
        } else if(l1>r2) r=mid1-1; else l=mid1+1;
    }
    return 0;
}
