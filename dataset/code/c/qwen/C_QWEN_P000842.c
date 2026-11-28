#include <stdio.h>
int main() {
    long long n, index, maxSum; scanf("%lld%lld%lld", &n, &index, &maxSum);
    long long l=1, r=maxSum, ans=1;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long left = index < mid ? (mid-1+mid-index)*(index)/2 : (mid-1)*mid/2 + (index-mid+1);
        long long right = n-1-index < mid ? (mid-1+mid-(n-1-index))*(n-1-index)/2 : (mid-1)*mid/2 + (n-1-index-mid+1);
        if(left+right+mid <= maxSum) { ans=mid; l=mid+1; } else r=mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}
