#include <stdio.h>
#include <stdbool.h>

bool isAutomorphic(long long n) {
    long long sq = n * n;
    long long temp = n;
    while (temp > 0) {
        if (temp % 10 != sq % 10) return false;
        temp /= 10;
        sq /= 10;
    }
    return true;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%s\n", isAutomorphic(n) ? "YES" : "NO");
    }
    return 0;
}