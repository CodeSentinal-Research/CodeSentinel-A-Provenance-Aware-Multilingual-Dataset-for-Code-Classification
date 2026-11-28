#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%s\n", (a + b > c && a + c > b && b + c > a) ? "Valid" : "Invalid");
    return 0;
}
