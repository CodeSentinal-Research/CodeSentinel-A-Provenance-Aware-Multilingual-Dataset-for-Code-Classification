#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 1; i <= n; i++) printf("%d%s", i, i == n ? "\n" : " ");
    return 0;
}
