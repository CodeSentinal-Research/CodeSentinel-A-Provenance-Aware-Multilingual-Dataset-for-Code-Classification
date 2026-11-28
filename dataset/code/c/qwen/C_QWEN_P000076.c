#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double d = b * b - 4 * a * c;
    if (d > 0) printf("%.2f %.2f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
    else if (d == 0) printf("%.2f\n", -b / (2 * a));
    else printf("%.2f+%.2fi %.2f-%.2fi\n", -b / (2 * a), sqrt(-d) / (2 * a), -b / (2 * a), sqrt(-d) / (2 * a));
    return 0;
}
