#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    if(n <= 1) { printf("false\n"); return 0; }
    int prime = 1;
    for(long long i=2; i*i<=n; i++) { if(n % i == 0) { prime = 0; break; } }
    printf("%s\n", prime ? "true" : "false");
    return 0;
}
