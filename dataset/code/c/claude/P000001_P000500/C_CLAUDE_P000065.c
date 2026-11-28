#include <stdlib.h>

long long gcdC(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return llabs(a);
}

long long lcmC(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (llabs(a) / gcdC(a, b)) * llabs(b);
}

long long lcmOfThree(int a, int b, int c) {
    return lcmC(lcmC(a, b), c);
}
