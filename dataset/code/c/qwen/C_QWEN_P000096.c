#include <stdio.h>

int main() {
    int n, s = 0, p = 1;
    scanf("%d", &n);
    int t = n;
    while (t > 0) {
        s += t % 10;
        p *= t % 10;
        t /= 10;
    }
    printf("%s\n", s == p ? "Spy" : "Not Spy");
    return 0;
}
