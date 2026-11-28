#include <stdio.h>

int main(void) {
    double fahrenheit;

    if (scanf("%lf", &fahrenheit) != 1) {
        return 1;
    }

    printf("%.2f\n", (fahrenheit - 32.0) * 5.0 / 9.0);

    return 0;
}
