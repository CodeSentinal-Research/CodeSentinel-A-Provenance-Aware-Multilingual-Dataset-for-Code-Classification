#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);
    long long s = (long long)sqrt((double)n);
    printf("%s\n", s * s == n ? "Perfect Square" : "Not Perfect Square");
    return 0;
}
