#include <stdio.h>

int main(void) {
    double a, b;
    if (scanf("%lf %lf", &a, &b) != 2) return 1;
    if (b == 0.0) {
        printf("Undefined\n");
    } else {
        printf("%.6f\n", a / b);
    }
    return 0;
}
