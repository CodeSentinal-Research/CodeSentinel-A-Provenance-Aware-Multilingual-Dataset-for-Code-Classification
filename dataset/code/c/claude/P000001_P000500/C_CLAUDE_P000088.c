#include <stdbool.h>
#include <math.h>

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    long long r = (long long)sqrt(num);
    return r * r == num;
}
