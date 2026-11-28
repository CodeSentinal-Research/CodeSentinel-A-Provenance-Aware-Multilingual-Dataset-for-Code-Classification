#include <stdio.h>
long long gcd(long long a, long long b) { while(b) { long long t=b; b=a%b; a=t; } return a; }
int main() {
    int n; scanf("%d", &n); long long a[n];
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    long long res = a[0];
    for(int i=1; i<n; i++) res = (res / gcd(res, a[i])) * a[i];
    printf("%lld\n", res);
    return 0;
}
