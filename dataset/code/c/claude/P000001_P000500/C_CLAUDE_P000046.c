#include <stdbool.h>

bool isDivisible(int a, int b) {
    if (b == 0) return false;
    return a % b == 0;
}
