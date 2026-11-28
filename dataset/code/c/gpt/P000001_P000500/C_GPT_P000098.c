#include <stdio.h>

int is_prime(int n) { if (n <= 1) return 0; for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0; return 1; }

int main(void) {
    int n; long long sum = 0;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 2; i <= n; i++) if (is_prime(i)) sum += i;
    printf("%lld\n", sum);
    return 0;
}
