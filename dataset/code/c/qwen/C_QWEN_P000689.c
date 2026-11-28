#include <stdio.h>
long long prod(long long n) { if(n==0) return 1; return (n%10) * prod(n/10); }
int main() { long long n; scanf("%lld", &n); printf("%lld\n", n==0?0:prod(n)); return 0; }
