#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = n; i >= 1; i--) printf("%d%s", i, i == 1 ? "\n" : " ");
    return 0;
}
