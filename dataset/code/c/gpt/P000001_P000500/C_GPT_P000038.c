#include <stdio.h>
#include <math.h>

int main(void) {
    double principal, rate, time;
    if (scanf("%lf %lf %lf", &principal, &rate, &time) != 3) return 1;
    double amount = principal * pow(1.0 + rate / 100.0, time);
    printf("%.2f\n", amount - principal);
    return 0;
}
