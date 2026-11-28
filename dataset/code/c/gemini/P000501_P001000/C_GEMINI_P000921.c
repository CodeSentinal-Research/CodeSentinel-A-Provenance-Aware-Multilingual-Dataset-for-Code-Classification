#include <stdio.h>
#include <stdlib.h>

void printDigitFrequency(long long n) {
    int freq[10] = {0};
    n = llabs(n);
    if (n == 0) {
        freq[0] = 1;
    } else {
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d%s", freq[i], (i == 9 ? "" : " "));
    }
    printf("\n");
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printDigitFrequency(n);
    }
    return 0;
}