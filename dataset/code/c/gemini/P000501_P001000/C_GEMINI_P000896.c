#include <stdio.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
int arrayGcd(const int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res = gcd(res, arr[i]);
    }
    return res;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%d\n", arrayGcd(arr, n));
    }
    return 0;
}