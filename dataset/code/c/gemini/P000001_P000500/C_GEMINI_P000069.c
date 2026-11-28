#include <stdio.h>
int main() {
    double r;
    if (scanf("%lf", &r) == 1) printf("%.5f\n", 2 * 3.14159 * r);
    return 0;
}