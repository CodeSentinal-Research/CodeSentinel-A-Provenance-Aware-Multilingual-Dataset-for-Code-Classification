#include <stdio.h>
long long modpow(long long b, long long e, long long m) { if(e==0) return 1; long long h=modpow(b, e/2, m); h=(h*h)%m; if(e%2) h=(h*b)%m; return h; }
int main() { long long b, e, m; scanf("%lld %lld %lld", &b, &e, &m); printf("%lld\n", modpow(b, e, m)); return 0; }
