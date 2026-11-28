#include <stdio.h>

/* Generate Binary Numbers */
int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    for (int x = 1; x <= n; x++) {
        int bits[64], p = 0, v = x;
        while (v) { bits[p++] = v & 1; v >>= 1; }
        for (int i = p - 1; i >= 0; i--) putchar(bits[i] + '0');
        putchar(x == n ? '\n' : ' ');
    }

    return 0;
}
