#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long l=1, r=n, res=0;
    while(l<=r) { long long mid=l+(r-l)/2; if(mid*(mid+1)/2 <= n) { res=mid; l=mid+1; } else r=mid-1; }
    printf("%lld\n", res);
    return 0;
}
