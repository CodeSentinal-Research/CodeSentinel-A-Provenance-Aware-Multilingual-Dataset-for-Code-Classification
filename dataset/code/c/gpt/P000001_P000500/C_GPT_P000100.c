#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) { long long val = 1; for (int j = 0; j <= i; j++) { printf("%lld ", val); val = val * (i - j) / (j + 1); } printf("\n"); }
    return 0;
}
