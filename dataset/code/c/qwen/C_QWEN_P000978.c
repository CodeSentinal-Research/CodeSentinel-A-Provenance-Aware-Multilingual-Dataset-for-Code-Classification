#include <stdio.h>
#include <math.h>
int main() {
    long long x1, y1, x2, y2, x3, y3;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
    long long area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
    if(area == 0) { printf("Not a Triangle\n"); return 0; }
    double a = sqrt((double)(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    double b = sqrt((double)(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
    double c = sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    if(fabs(a-b) < 1e-9 && fabs(b-c) < 1e-9) printf("Equilateral\n");
    else if(fabs(a-b) < 1e-9 || fabs(b-c) < 1e-9 || fabs(a-c) < 1e-9) printf("Isosceles\n");
    else printf("Scalene\n");
    return 0;
}
