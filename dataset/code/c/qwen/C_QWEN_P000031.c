#include <stdio.h>

int main() {
    int n, orig, d = 0;
    scanf("%d", &n);
    orig = n;
    int t = n;
    while (t > 0) { d++; t /= 10; }
    t = n;
    long long s = 0;
    while (t > 0) {
        int rem = t % 10;
        long long p = 1;
        for (int i = 0; i < d; i++) p *= rem;
        s += p;
        t /= 10;
    }
    printf("%s\n", s == orig ? "Armstrong" : "Not Armstrong");
    return 0;
}
