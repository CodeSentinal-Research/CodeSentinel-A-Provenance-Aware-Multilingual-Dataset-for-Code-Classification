#include <stdio.h>
long long gcd(long long a, long long b) { while(b) { long long t=b; b=a%b; a=t; } return a; }
int main() {
    long long num, den; scanf("%lld%lld", &num, &den);
    long long g = gcd(num, den);
    printf("%lld %lld\n", num / g, den / g);
    return 0;
}
