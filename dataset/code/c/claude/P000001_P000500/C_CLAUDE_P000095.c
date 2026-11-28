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
