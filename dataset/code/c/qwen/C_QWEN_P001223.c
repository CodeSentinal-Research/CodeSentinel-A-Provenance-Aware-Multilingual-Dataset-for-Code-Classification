#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a = 1, b = 2;
    for(int i=3; i<=n; i++) { long long t = a + b; a = b; b = t; }
    printf("%lld\n", n == 1 ? 2 : (n == 2 ? 3 : b));
    return 0;
}
