#include <stdio.h>
int main() {
    long long num; scanf("%lld", &num);
    long long l=1, r=num, found=0;
    while(l<=r) { long long mid=l+(r-l)/2; if(mid*mid==num) { found=1; break; } else if(mid*mid<num) l=mid+1; else r=mid-1; }
    printf("%s\n", found?"true":"false");
    return 0;
}
