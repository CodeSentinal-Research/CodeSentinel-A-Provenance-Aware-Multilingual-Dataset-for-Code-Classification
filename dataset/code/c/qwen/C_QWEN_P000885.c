#include <stdio.h>
#include <math.h>
int main() {
    long long n; scanf("%lld", &n);
    long long orig = n, sum = 0;
    int digits = 0; long long temp = n;
    while(temp > 0) { digits++; temp /= 10; }
    temp = n;
    while(temp > 0) { sum += (long long)pow(temp % 10, digits); temp /= 10; }
    printf("%s\n", sum == orig ? "true" : "false");
    return 0;
}
