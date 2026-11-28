#include <stdio.h>
int main() {
    int n, threshold; scanf("%d %d", &n, &threshold);
    int nums[1000];
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    int l=1, r=1000000, res=r;
    while(l<=r) {
        int mid = l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<n; i++) sum += (nums[i]+mid-1)/mid;
        if(sum<=threshold) { res=mid; r=mid-1; } else l=mid+1;
    }
    printf("%d\n", res);
    return 0;
}
