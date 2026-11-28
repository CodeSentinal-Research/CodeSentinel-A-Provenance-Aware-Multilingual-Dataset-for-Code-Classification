#include <stdio.h>

int main() {
    long long n, orig, r = 0;
    scanf("%lld", &n);
    orig = n < 0 ? -n : n;
    long long t = orig;
    while (t > 0) {
        r = r * 10 + t % 10;
        t /= 10;
    }
    printf("%s\n", orig == r ? "Palindrome" : "Not Palindrome");
    return 0;
}
