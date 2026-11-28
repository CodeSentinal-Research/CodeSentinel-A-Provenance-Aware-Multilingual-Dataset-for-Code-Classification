#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;
    double d = b * b - 4.0 * a * c;
    if (d > 0) printf("%.2f %.2f\n", (-b + sqrt(d)) / (2.0 * a), (-b - sqrt(d)) / (2.0 * a));
    else if (d == 0) printf("%.2f\n", -b / (2.0 * a));
    else printf("Imaginary Roots\n");
    return 0;
}
