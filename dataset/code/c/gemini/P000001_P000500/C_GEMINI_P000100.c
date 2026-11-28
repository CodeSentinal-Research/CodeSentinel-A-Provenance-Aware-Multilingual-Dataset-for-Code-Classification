#include <stdio.h>

void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        long long val = 1;
        for (int j = 0; j <= i; j++) {
            printf("%lld%s", val, (j == i ? "" : " "));
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printPascalTriangle(n);
    }
    return 0;
}