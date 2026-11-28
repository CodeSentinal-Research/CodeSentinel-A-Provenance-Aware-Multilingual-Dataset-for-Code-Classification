#include <stdio.h>
int main() {
    long long x; scanf("%lld", &x);
    long long l=0, r=x, res=0;
    while(l<=r) { long long mid=l+(r-l)/2; if(mid*mid<=x) { res=mid; l=mid+1; } else r=mid-1; }
    printf("%lld\n", res);
    return 0;
}
