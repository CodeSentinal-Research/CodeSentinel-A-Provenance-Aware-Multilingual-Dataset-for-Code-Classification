#include <stdio.h>
int main() {
    long long x; int n; scanf("%lld%d", &x, &n);
    long long rem[n], mod[n];
    for(int i=0; i<n; i++) scanf("%lld", &rem[i]);
    for(int i=0; i<n; i++) scanf("%lld", &mod[i]);
    int ok = 1;
    for(int i=0; i<n; i++) if(x % mod[i] != rem[i]) { ok = 0; break; }
    printf("%s\n", ok ? "true" : "false");
    return 0;
}
