#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", countSetBits(n));
    }
    return 0;
}