#include <stdio.h>
#include <stdbool.h>

bool isEven(int n) {
    return (n & 1) == 0;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%s\n", isEven(n) ? "Even" : "Odd");
    }
    return 0;
}