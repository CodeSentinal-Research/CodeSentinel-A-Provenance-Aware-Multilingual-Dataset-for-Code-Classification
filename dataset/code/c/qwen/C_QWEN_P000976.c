#include <stdio.h>
#include <math.h>
int main() {
    long long x1, y1, x2, y2, x3, y3;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
    double area = fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
    printf("%.6f\n", area);
    return 0;
}
