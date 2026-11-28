#include <stdio.h>

int main(void) {
    double a, d; int n;
    if (scanf("%lf %lf %d", &a, &d, &n) != 3) return 1;
    printf("%.2f\n", (n / 2.0) * (2.0 * a + (n - 1) * d));
    return 0;
}
