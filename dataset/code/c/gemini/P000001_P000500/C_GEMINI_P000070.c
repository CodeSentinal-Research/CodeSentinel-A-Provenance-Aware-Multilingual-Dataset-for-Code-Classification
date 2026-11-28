#include <stdio.h>
int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        int valid = (a + b > c) && (a + c > b) && (b + c > a);
        printf("%s\n", valid ? "Valid" : "Invalid");
    }
    return 0;
}