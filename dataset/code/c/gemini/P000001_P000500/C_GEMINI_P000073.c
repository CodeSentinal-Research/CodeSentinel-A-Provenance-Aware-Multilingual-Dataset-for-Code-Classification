#include <stdio.h>
int main() {
    double l, b, h;
    if (scanf("%lf %lf %lf", &l, &b, &h) == 3) printf("%.2f\n", l * b * h);
    return 0;
}