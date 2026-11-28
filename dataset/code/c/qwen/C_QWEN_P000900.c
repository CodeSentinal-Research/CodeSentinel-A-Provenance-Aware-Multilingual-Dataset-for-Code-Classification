#include <stdio.h>
#include <math.h>
int main() {
    long long n; scanf("%lld", &n);
    long long sum = 0, temp = labs(n);
    while(temp > 0) { sum += temp % 10; temp /= 10; }
    printf("%s\n", sum % 9 == 0 ? "true" : "false");
    return 0;
}
