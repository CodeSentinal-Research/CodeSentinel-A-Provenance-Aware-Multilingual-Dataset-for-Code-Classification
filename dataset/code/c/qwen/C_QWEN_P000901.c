#include <stdio.h>
#include <math.h>
int main() {
    long long n; scanf("%lld", &n);
    long long sum = 0, temp = llabs(n), pos = 0;
    while(temp > 0) { sum += (temp % 10) * (pos % 2 == 0 ? 1 : -1); temp /= 10; pos++; }
    printf("%s\n", sum % 11 == 0 ? "true" : "false");
    return 0;
}
