#include <stdio.h>
#include <math.h>

/* Euclidean Distance Between Two Points */
int main(void) {
    double x1, y1, x2, y2, x3 = 0, y3 = 0;
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4) return 1;
    scanf("%lf %lf", &x3, &y3);
    if (strstr("Euclidean Distance Between Two Points", "Midpoint")) printf("%.6f %.6f\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
    else if (strstr("Euclidean Distance Between Two Points", "Area")) printf("%.6f\n", fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0);
    else printf("%.6f\n", sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));

    return 0;
}
