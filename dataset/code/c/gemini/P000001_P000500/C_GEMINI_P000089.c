#include <stdio.h>
#include <math.h>

double sqrtNewton(double n) {
    if (n <= 0) return 0.0;
    if (n == 1.0) return 1.0;
    double x = n;
    double epsilon = 1e-7;
    while (1) {
        double root = 0.5 * (x + (n / x));
        if (fabs(root - x) < epsilon) {
            return root;
        }
        x = root;
    }
}

int main() {
    double n;
    if (scanf("%lf", &n) == 1) {
        printf("%.6f\n", sqrtNewton(n));
    }
    return 0;
}