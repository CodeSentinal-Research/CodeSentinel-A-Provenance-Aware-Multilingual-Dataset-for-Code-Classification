#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long next = n + 1;
    while(1) {
        int prime = 1;
        for(long long i=2; i*i<=next; i++) { if(next % i == 0) { prime = 0; break; } }
        if(prime) { printf("%lld\n", next); return 0; }
        next++;
    }
    return 0;
}
