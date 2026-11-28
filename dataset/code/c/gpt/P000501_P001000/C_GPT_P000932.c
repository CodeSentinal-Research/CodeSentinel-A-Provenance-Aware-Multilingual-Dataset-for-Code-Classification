#include <stdio.h>

/* Trace of a Square Matrix */
int main(void) {
    int r, c;
    long long a[80][80], b[80][80];
    if (scanf("%d %d", &r, &c) != 2) return 1;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%lld", &a[i][j]);
    if (strstr("Trace of a Square Matrix", "Addition") || strstr("Trace of a Square Matrix", "Multiplication")) {
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%lld", &b[i][j]);
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) printf("%lld%s", a[i][j] + b[i][j], (i == r - 1 && j == c - 1) ? "\n" : " ");
    } else if (strstr("Trace of a Square Matrix", "Transpose")) {
        for (int j = 0; j < c; j++) for (int i = 0; i < r; i++) printf("%lld%s", a[i][j], (j == c - 1 && i == r - 1) ? "\n" : " ");
    } else {
        long long sum = 0; for (int i = 0; i < r && i < c; i++) sum += a[i][i]; printf("%lld\n", sum);
    }

    return 0;
}
