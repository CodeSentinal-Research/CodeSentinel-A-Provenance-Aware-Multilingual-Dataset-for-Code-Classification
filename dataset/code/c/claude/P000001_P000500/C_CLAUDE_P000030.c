#include <stdlib.h>

long long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int x = abs(a), y = abs(b);
    int tempA = x, tempB = y;
    while (tempB != 0) {
        int t = tempB;
        tempB = tempA % tempB;
        tempA = t;
    }
    return ((long long)x / tempA) * y;
}
