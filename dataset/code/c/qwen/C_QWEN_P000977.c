#include <stdio.h>
int main() {
    long long x1, y1, x2, y2, x3, y3;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
    long long area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
    printf("%s\n", area == 0 ? "true" : "false");
    return 0;
}
