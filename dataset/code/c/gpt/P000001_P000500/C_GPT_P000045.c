#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long sum = 0; for (int i = 1; i <= n; i++) sum += (long long)i * i; printf("%lld\n", sum);
    return 0;
}
