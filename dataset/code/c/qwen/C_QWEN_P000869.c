#include <stdio.h>
int main() {
    int dividend, divisor; scanf("%d%d", &dividend, &divisor);
    if(dividend == -2147483648 && divisor == -1) { printf("2147483647\n"); return 0; }
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    long long a = labs(dividend), b = labs(divisor), res = 0;
    while(a >= b) {
        long long temp = b, multiple = 1;
        while(a >= (temp << 1)) { temp <<= 1; multiple <<= 1; }
        a -= temp; res += multiple;
    }
    printf("%lld\n", sign * res);
    return 0;
}
