#include <stdio.h>
long long gcd(long long a, long long b) { while(b) { long long t=b; b=a%b; a=t; } return a; }
int main() {
    long long a, b; scanf("%lld%lld", &a, &b);
    printf("%lld\n", (a / gcd(a, b)) * b);
    return 0;
}
