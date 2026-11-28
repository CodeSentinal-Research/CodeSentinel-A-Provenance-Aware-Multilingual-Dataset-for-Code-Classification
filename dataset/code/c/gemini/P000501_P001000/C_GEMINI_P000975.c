#include <stdio.h>

int main() {
    double x1, y1, x2, y2;
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) == 4) {
        printf("%.6f %.6f\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
    }
    return 0;
}