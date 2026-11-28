#include <stdlib.h>

int countEvenDigits(int n) {
    n = abs(n);
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        if ((n % 10) % 2 == 0) count++;
        n /= 10;
    }
    return count;
}
