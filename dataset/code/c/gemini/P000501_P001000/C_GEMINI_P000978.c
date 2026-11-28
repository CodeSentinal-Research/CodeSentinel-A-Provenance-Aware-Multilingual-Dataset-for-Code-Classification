#include <stdio.h>

const char* triangleType(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    if ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0) {
        return "Not a Triangle";
    }
    long long d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    long long d2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    long long d3 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

    if (d1 == d2 && d2 == d3) return "Equilateral";
    if (d1 == d2 || d2 == d3 || d3 == d1) return "Isosceles";
    return "Scalene";
}

int main() {
    long long x1, y1, x2, y2, x3, y3;
    if (scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        printf("%s\n", triangleType(x1, y1, x2, y2, x3, y3));
    }
    return 0;
}