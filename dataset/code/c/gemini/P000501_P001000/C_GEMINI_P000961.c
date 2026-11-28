#include <stdio.h>

int main() {
    long long a, b, c;
    long long minx, maxx, miny, maxy;
    if (scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &minx, &maxx, &miny, &maxy) == 7) {
        long long count = 0;
        for (long long x = minx; x <= maxx; x++) {
            long long rem = c - a * x;
            if (rem % b == 0) {
                long long y = rem / b;
                if (y >= miny && y <= maxy) count++;
            }
        }
        printf("%lld\n", count);
    }
    return 0;
}