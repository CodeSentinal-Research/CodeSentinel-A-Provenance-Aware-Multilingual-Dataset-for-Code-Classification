#include <stdio.h>
int main() {
    long long x1, y1, x2, y2; scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    printf("%.1f %.1f\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
    return 0;
}
