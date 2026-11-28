#include <stdio.h>
int main() {
    double s;
    if (scanf("%lf", &s) == 1) printf("%.2f\n", s * s);
    return 0;
}