#include <stdio.h>

int main(void) {
    double side;
    if (scanf("%lf", &side) != 1) return 1;
    printf("%.2f\n", 4.0 * side);
    return 0;
}
