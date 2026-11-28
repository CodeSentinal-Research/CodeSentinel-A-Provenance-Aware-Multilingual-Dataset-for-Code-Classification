#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a = 1, b = 1;
    for(int i=2; i<=n; i++) { long long t = a + b; a = b; b = t; }
    printf("%lld\n", b);
    return 0;
}
