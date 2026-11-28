#include <stdio.h>

int main() {
    int x, n;
    long long r = 1;
    scanf("%d %d", &x, &n);
    for (int i = 0; i < n; i++) r *= x;
    printf("%lld\n", r);
    return 0;
}
