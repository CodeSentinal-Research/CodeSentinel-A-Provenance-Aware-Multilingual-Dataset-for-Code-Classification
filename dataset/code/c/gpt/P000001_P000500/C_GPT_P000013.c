#include <stdio.h>

int main(void) {
    double radius;

    if (scanf("%lf", &radius) != 1) {
        return 1;
    }

    printf("%.2f\n", 3.141592653589793 * radius * radius);

    return 0;
}
