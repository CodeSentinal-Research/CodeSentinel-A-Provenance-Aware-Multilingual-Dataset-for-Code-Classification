#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double r1 = (-b + sqrt(d)) / (2 * a);
            double r2 = (-b - sqrt(d)) / (2 * a);
            printf("%.2f %.2f\n", r1, r2);
        } else if (d == 0) {
            printf("%.2f\n", -b / (2 * a));
        } else {
            printf("Complex Roots\n");
        }
    }
    return 0;
}