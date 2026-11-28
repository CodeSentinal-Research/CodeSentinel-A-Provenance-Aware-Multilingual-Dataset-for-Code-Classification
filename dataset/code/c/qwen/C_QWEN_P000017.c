#include <stdio.h>

int main() {
    double f;
    scanf("%lf", &f);
    printf("%.2f\n", (f - 32.0) * 5.0 / 9.0);
    return 0;
}
