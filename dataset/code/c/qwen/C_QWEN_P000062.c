#include <stdio.h>

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

int main() {
    int n, s = 0;
    scanf("%d", &n);
    int t = n;
    while (t > 0) {
        s += fact(t % 10);
        t /= 10;
    }
    printf("%s\n", s == n ? "Strong" : "Not Strong");
    return 0;
}
