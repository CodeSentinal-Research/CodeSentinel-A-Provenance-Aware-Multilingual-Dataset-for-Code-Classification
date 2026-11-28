#include <stdio.h>
long long gcd(long long a, long long b) { while(b) { long long t=b; b=a%b; a=t; } return a; }
int main() {
    long long a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
    printf("%s\n", c % gcd(a, b) == 0 ? "true" : "false");
    return 0;
}
