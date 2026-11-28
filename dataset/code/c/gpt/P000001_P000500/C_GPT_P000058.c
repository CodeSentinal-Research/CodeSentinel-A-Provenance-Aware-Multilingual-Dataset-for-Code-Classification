#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long sum = 0; for (int i = 1, term = 2; i <= n; i++, term += 2) sum += term; printf("%lld\n", sum);
    return 0;
}
