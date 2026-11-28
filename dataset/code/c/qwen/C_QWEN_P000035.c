#include <stdio.h>

int main() {
    int n, s = 1;
    scanf("%d", &n);
    if (n <= 1) s = 0;
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                s += i;
                if (i != n / i) s += n / i;
            }
        }
    }
    printf("%s\n", s == n ? "Perfect" : "Not Perfect");
    return 0;
}
