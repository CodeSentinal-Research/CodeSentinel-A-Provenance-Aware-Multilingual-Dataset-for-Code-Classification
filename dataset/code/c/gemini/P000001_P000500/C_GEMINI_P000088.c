#include <stdio.h>
#include <math.h>
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        if (n < 0) { printf("Not Perfect Square\n"); return 0; }
        long long sq = (long long) sqrt(n);
        printf("%s\n", sq * sq == n ? "Perfect Square" : "Not Perfect Square");
    }
    return 0;
}