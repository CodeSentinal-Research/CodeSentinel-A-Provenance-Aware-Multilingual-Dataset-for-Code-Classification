#include <stdio.h>
#include <math.h>

int main() {
    double a, r, n;
    scanf("%lf %lf %lf", &a, &r, &n);
    if (r == 1.0) printf("%.2f\n", a * n);
    else printf("%.2f\n", a * (pow(r, n) - 1.0) / (r - 1.0));
    return 0;
}
