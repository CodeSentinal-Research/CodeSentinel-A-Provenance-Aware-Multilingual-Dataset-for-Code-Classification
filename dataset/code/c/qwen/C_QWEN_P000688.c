#include <stdio.h>
int count(long long n) { if(n==0) return 0; return 1 + count(n/10); }
int main() { long long n; scanf("%lld", &n); printf("%d\n", n==0?1:count(n)); return 0; }
