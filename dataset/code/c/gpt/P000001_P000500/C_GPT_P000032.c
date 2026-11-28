#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 1; i <= n; i++) if (n % i == 0) printf("%d%s", i, i == n ? "\n" : " ");
    return 0;
}
