#include <stdio.h>
#include <stdbool.h>

bool isNeon(int n) {
    long long sq = (long long)n * n;
    long long sum = 0;
    while (sq > 0) {
        sum += sq % 10;
        sq /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isNeon(n) ? "YES" : "NO");
    }
    return 0;
}