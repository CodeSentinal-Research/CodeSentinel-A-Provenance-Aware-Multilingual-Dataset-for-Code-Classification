#include <stdio.h>
int main() {
    double b, h;
    if (scanf("%lf %lf", &b, &h) == 2) printf("%.2f\n", 0.5 * b * h);
    return 0;
}