#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int first = 1;
    for(long long i=2; i*i<=n; i++) {
        while(n % i == 0) { if(!first) printf(" "); printf("%lld", i); first = 0; n /= i; }
    }
    if(n > 1) { if(!first) printf(" "); printf("%lld", n); }
    printf("\n");
    return 0;
}
