#include <stdio.h>

int main(void) {
    double a, r; int n;
    if (scanf("%lf %lf %d", &a, &r, &n) != 3) return 1;
    double sum = 0.0, term = a; for (int i = 0; i < n; i++) { sum += term; term *= r; } printf("%.2f\n", sum);
    return 0;
}
