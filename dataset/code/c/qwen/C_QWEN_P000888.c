#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long sq = n * n;
    long long temp = n;
    while(temp > 0) { if(sq % 10 != temp % 10) { printf("false\n"); return 0; } sq /= 10; temp /= 10; }
    printf("true\n");
    return 0;
}
