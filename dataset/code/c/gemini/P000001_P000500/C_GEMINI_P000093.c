#include <stdio.h>
#include <math.h>

double sumOfGP(double a, double r, int n) {
    if (n <= 0) return 0.0;
    if (r == 1.0) return a * n;
    return a * (1.0 - pow(r, n)) / (1.0 - r);
}

int main() {
    double a, r;
    int n;
    if (scanf("%lf %lf %d", &a, &r, &n) == 3) {
        printf("%.2f\n", sumOfGP(a, r, n));
    }
    return 0;
}