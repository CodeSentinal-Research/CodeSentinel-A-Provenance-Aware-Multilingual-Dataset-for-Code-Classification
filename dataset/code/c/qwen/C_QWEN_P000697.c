#include <stdio.h>
int prime(long long n, long long i) { if(n<=1) return 0; if(i*i>n) return 1; if(n%i==0) return 0; return prime(n, i+1); }
int main() { long long n; scanf("%lld", &n); printf("%s\n", prime(n, 2)?"true":"false"); return 0; }
