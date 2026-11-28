#include <stdio.h>

int main() {
    double s, t;
    scanf("%lf %lf", &s, &t);
    printf("%.2f\n", (s / t) * 100.0);
    return 0;
}
