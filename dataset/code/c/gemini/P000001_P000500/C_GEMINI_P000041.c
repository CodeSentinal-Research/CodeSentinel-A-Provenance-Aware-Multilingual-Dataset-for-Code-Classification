#include <stdio.h>
int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        printf("%.2f\n", (a + b + c) / 3.0);
    }
    return 0;
}