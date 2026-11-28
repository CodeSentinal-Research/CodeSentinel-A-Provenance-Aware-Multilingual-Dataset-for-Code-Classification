#include <stdio.h>

int main() {
    int n, p = 1;
    scanf("%d", &n);
    if (n <= 1) p = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) p = 0;
    }
    printf("%s\n", p ? "Prime" : "Not Prime");
    return 0;
}
