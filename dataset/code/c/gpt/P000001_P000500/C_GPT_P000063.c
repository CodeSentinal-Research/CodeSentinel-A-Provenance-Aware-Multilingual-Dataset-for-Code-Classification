#include <stdio.h>

int is_prime(int n) { if (n <= 1) return 0; for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0; return 1; }

int main(void) {
    int low, high, first = 1;
    if (scanf("%d %d", &low, &high) != 2) return 1;
    for (int i = low; i <= high; i++) if (is_prime(i)) { printf("%s%d", first ? "" : " ", i); first = 0; }
    printf("\n");
    return 0;
}
