#include <stdio.h>
int main() {
    double r, h;
    if (scanf("%lf %lf", &r, &h) == 2) printf("%.5f\n", 3.14159 * r * r * h);
    return 0;
}