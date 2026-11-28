#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int nums[1000]; long long total=0, max_n=0;
    for(int i=0; i<n; i++) { scanf("%d", &nums[i]); total+=nums[i]; if(nums[i]>max_n) max_n=nums[i]; }
    long long l=max_n, r=total, res=total;
    while(l<=r) {
        long long mid = l+(r-l)/2;
        long long sum=0, parts=1;
        for(int i=0; i<n; i++) {
            if(sum+nums[i]>mid) { parts++; sum=nums[i]; }
            else sum+=nums[i];
        }
        if(parts<=m) { res=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", res);
    return 0;
}
