#include <stdio.h>
long long phi(long long n) {
    long long res = n;
    for(long long i=2; i*i<=n; i++) {
        if(n % i == 0) { while(n % i == 0) n /= i; res -= res / i; }
    }
    if(n > 1) res -= res / n;
    return res;
}
int main() {
    long long n, l, r; scanf("%lld%lld%lld", &n, &l, &r);
    long long count = 0;
    for(long long i=l; i<=r; i++) {
        long long temp = i; long long res = temp;
        for(long long j=2; j*j<=temp; j++) {
            if(temp % j == 0) { while(temp % j == 0) temp /= j; res -= res / j; }
        }
        if(temp > 1) res -= res / temp;
        // Check if gcd(i, n) == 1
        long long a = i, b = n;
        while(b) { long long t=b; b=a%b; a=t; }
        if(a == 1) count++;
    }
    printf("%lld\n", count);
    return 0;
}
