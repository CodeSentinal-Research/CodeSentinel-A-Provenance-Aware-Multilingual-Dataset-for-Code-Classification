#include <stdio.h>

int main(void) {
    double length, breadth;

    if (scanf("%lf %lf", &length, &breadth) != 2) {
        return 1;
    }

    printf("%.2f\n", 2.0 * (length + breadth));

    return 0;
}
