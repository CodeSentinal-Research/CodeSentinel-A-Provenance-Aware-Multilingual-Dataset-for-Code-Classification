#include <stdio.h>

int main() {
    double l, b;
    if (scanf("%lf %lf", &l, &b) == 2) {
        printf("%.2f\n", 2 * (l + b));
    }
    return 0;
}