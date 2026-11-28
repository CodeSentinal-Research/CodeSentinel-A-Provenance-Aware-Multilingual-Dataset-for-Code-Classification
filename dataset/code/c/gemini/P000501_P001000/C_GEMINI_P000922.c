#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long sumDigitsUpTo(long long n) {
    if (n <= 0) return 0;
    char s[30];
    sprintf(s, "%lld", n);
    int d = strlen(s);
    if (d == 1) return n * (n + 1) / 2;
    long long first = s[0] - '0';
    long long rem = atoll(s + 1);
    long long p = (long long)pow(10, d - 1);

    long long ans = first * 45 * (d - 1) * (p / 10);
    ans += (first * (first - 1) / 2) * p;
    ans += first * (rem + 1);
    ans += sumDigitsUpTo(rem);
    return ans;
}

int main() {
    long long l, r;
    if (scanf("%lld %lld", &l, &r) == 2) {
        printf("%lld\n", sumDigitsUpTo(r) - sumDigitsUpTo(l - 1));
    }
    return 0;
}