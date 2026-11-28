#include <stdio.h>

int main(void) {
    double units, bill = 0.0;
    if (scanf("%lf", &units) != 1) return 1;
    if (units <= 100) bill = units * 1.5; else if (units <= 200) bill = 100 * 1.5 + (units - 100) * 2.5; else bill = 100 * 1.5 + 100 * 2.5 + (units - 200) * 4.0; printf("%.2f\n", bill);
    return 0;
}
