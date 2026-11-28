#include <stdio.h>

int main() {
    int n, bits[32], c = 0;
    scanf("%d", &n);
    if (n == 0) printf("0\n");
    else {
        while (n > 0) { bits[c++] = n % 2; n /= 2; }
        for (int i = c - 1; i >= 0; i--) printf("%d", bits[i]);
        printf("\n");
    }
    return 0;
}
