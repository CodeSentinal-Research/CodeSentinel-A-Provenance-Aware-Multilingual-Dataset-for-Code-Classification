#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);
    long long ans = 0;
    while (dvd >= dvs) {
        long long temp = dvs, m = 1;
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return (int)(sign * ans);
}