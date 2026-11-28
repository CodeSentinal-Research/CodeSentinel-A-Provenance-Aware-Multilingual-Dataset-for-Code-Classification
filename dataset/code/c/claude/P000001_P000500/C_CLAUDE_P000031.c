#include <stdbool.h>
#include <math.h>

bool isArmstrong(int n) {
    if (n < 0) return false;
    int temp = n, digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    long long sum = 0;
    while (temp > 0) {
        int d = temp % 10;
        sum += (long long)pow(d, digits);
        temp /= 10;
    }
    return sum == n;
}
