#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long sum = 0; for (int i = 2; i <= n; i += 2) sum += i; printf("%lld\n", sum);
    return 0;
}
