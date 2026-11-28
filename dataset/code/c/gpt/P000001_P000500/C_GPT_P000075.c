#include <stdio.h>

int main(void) {
    double r, h;
    if (scanf("%lf %lf", &r, &h) != 2) return 1;
    printf("%.2f\n", 3.141592653589793 * r * r * h);
    return 0;
}
