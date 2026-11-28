#include <stdio.h>

int main() {
    double a, d, n;
    scanf("%lf %lf %lf", &a, &d, &n);
    printf("%.2f\n", (n / 2.0) * (2.0 * a + (n - 1.0) * d));
    return 0;
}
