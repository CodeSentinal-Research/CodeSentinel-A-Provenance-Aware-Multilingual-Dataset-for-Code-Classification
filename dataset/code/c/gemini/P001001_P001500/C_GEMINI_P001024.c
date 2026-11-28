#include <stdio.h>

int main() {
    int i, n;
    if (scanf("%d %d", &i, &n) == 2) {
        int l = (2 * i + 1 < n) ? 2 * i + 1 : -1;
        int r = (2 * i + 2 < n) ? 2 * i + 2 : -1;
        printf("%d %d\n", l, r);
    }
    return 0;
}