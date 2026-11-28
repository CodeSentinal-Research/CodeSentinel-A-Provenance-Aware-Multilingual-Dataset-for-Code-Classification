#include <stdio.h>

int main(void) {
    double r;
    if (scanf("%lf", &r) != 1) return 1;
    printf("%.2f\n", (4.0 / 3.0) * 3.141592653589793 * r * r * r);
    return 0;
}
