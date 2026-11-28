#include <stdio.h>
int main() {
    long long a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
    long long sum = a + b + c;
    long long max_val = a > b ? (a > c ? a : c) : (b > c ? b : c);
    long long res = sum - max_val;
    if(res > max_val) res = max_val;
    printf("%lld\n", res);
    return 0;
}
