#include <stdio.h>
int sumDigits(long long n) {
    int s = 0; while(n > 0) { s += n % 10; n /= 10; } return s;
}
int main() {
    long long l, r; scanf("%lld%lld", &l, &r);
    long long total = 0;
    for(long long i=l; i<=r; i++) total += sumDigits(i);
    printf("%lld\n", total);
    return 0;
}
