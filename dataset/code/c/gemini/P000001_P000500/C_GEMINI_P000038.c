#include <stdio.h>
#include <math.h>
int main() {
    double p, r, t;
    if (scanf("%lf %lf %lf", &p, &r, &t) == 3) {
        double a = p * pow(1.0 + r / 100.0, t);
        double ci = a - p;
        printf("%.2f\n", ci);
    }
    return 0;
}