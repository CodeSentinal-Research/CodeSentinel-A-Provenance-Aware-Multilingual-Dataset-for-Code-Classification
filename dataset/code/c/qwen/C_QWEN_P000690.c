#include <stdio.h>
void bin(long long n) { if(n==0) return; bin(n/2); printf("%d", n%2); }
int main() { long long n; scanf("%lld", &n); if(n==0) printf("0"); else bin(n); printf("\n"); return 0; }
