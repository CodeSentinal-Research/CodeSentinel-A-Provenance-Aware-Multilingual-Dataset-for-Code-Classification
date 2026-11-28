#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums1[1000];
    for(int i=0; i<n; i++) scanf("%d", &nums1[i]);
    int m; scanf("%d", &m);
    int nums2[1000];
    for(int i=0; i<m; i++) scanf("%d", &nums2[i]);
    for(int i=0; i<n; i++) {
        int found=-1;
        for(int j=0; j<m; j++) {
            if(nums2[j]==nums1[i]) {
                for(int k=j+1; k<m; k++) {
                    if(nums2[k]>nums1[i]) { found=nums2[k]; break; }
                }
                break;
            }
        }
        printf("%d%c", found, i==n-1?'\n':' ');
    }
    return 0;
}
