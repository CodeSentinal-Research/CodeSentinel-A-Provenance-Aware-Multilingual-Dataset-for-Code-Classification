#include <stdio.h>

int main(void) {
    double l, b, h;
    if (scanf("%lf %lf %lf", &l, &b, &h) != 3) return 1;
    printf("%.2f\n", l * b * h);
    return 0;
}
