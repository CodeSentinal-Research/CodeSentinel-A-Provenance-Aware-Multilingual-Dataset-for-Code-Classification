#include <stdio.h>

int main(void) {
    double principal, rate, time;

    if (scanf("%lf %lf %lf", &principal, &rate, &time) != 3) {
        return 1;
    }

    printf("%.2f\n", (principal * rate * time) / 100.0);

    return 0;
}
