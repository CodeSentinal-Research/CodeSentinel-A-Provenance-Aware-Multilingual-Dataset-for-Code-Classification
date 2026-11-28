#include <stdio.h>

void countEvenOdd(const int arr[], int n, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) (*even)++;
        else (*odd)++;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int even = 0, odd = 0;
        countEvenOdd(arr, n, &even, &odd);
        printf("Even: %d, Odd: %d\n", even, odd);
    }
    return 0;
}