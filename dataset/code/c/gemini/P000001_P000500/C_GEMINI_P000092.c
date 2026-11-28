#include <stdio.h>

double sumOfAP(double a, double d, int n) {
    if (n <= 0) return 0.0;
    return (n / 2.0) * (2.0 * a + (n - 1) * d);
}

int main() {
    double a, d;
    int n;
    if (scanf("%lf %lf %d", &a, &d, &n) == 3) {
        printf("%.2f\n", sumOfAP(a, d, n));
    }
    return 0;
}