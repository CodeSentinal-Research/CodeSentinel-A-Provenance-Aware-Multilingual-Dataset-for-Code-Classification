#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long l=1, r=n, found=0;
    while(l<=r) {
        long long mid = l+(r-l)/2;
        if(mid*mid==n) { found=1; break; }
        else if(mid*mid<n) l=mid+1; else r=mid-1;
    }
    printf("%s\n", found ? "Yes" : "No");
    return 0;
}
