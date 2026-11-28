#include <stdio.h>

int main() {
    double f;
    if (scanf("%lf", &f) == 1) {
        double c = (f - 32.0) * 5.0 / 9.0;
        printf("%.2f\n", c);
    }
    return 0;
}