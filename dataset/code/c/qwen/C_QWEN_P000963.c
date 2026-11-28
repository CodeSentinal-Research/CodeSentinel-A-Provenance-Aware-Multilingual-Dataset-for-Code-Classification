#include <stdio.h>
int main() {
    long long a, b, n; scanf("%lld%lld%lld", &a, &b, &n);
    int ok = 0;
    for(long long i=0; i*a<=n; i++) if((n - i*a) % b == 0) { ok = 1; break; }
    printf("%s\n", ok ? "true" : "false");
    return 0;
}
