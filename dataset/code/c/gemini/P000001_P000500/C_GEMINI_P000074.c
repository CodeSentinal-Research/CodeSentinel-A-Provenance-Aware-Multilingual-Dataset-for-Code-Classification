#include <stdio.h>
int main() {
    double r;
    if (scanf("%lf", &r) == 1) printf("%.5f\n", (4.0 / 3.0) * 3.14159 * r * r * r);
    return 0;
}