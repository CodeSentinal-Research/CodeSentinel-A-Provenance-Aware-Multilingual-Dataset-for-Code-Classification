#include <stdio.h>
#include <math.h>

int main() {
    double p, r, t;
    scanf("%lf %lf %lf", &p, &r, &t);
    double a = p * pow(1.0 + r / 100.0, (int)t);
    printf("%.2f\n", a - p);
    return 0;
}
