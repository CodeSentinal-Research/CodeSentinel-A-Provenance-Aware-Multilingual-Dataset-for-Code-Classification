#include <stdio.h>

int main() {
    double r;
    if (scanf("%lf", &r) == 1) {
        double pi = 3.14159;
        double area = pi * r * r;
        printf("%.5f\n", area);
    }
    return 0;
}