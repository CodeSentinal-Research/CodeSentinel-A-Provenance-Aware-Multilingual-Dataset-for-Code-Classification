#include <stdio.h>

int main(void) {
    int n, sum = 0;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 1; i <= n / 2; i++) if (n % i == 0) sum += i;
    printf("%s\n", (n > 0 && sum == n) ? "Perfect" : "Not Perfect");
    return 0;
}
