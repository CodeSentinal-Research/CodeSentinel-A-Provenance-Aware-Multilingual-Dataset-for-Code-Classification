#include <stdio.h>
long long phi(long long n) {
    long long res = n;
    for(long long i=2; i*i<=n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}
int main() {
    long long n; scanf("%lld", &n);
    printf("%lld\n", phi(n));
    return 0;
}
