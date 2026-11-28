#include <stdio.h>

int main(void) {
    double x;
    int n;
    double result = 1.0;

    if (scanf("%lf %d", &x, &n) != 2) {
        return 1;
    }

    int exp = n < 0 ? -n : n;
    for (int i = 0; i < exp; i++) result *= x;
    if (n < 0) result = 1.0 / result;
    printf("%.6f\n", result);

    return 0;
}
