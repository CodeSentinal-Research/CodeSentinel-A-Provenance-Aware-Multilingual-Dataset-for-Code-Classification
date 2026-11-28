#include <stdio.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Computes the Least Common Multiple (LCM).
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// Computes the Least Common Multiple (LCM).
long long arrayLcm(const int arr[], int n) {
    long long res = arr[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, arr[i]);
    }
    return res;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%lld\n", arrayLcm(arr, n));
    }
    return 0;
}