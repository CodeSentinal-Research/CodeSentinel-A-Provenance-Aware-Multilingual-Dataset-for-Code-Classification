#include <stdbool.h>
#include <stdlib.h>

bool isSpy(int n) {
    n = abs(n);
    int sum = 0, prod = 1;
    while (n > 0) {
        int d = n % 10;
        sum += d;
        prod *= d;
        n /= 10;
    }
    return sum == prod;
}
