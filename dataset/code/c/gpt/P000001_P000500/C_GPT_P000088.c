#include <stdio.h>

int main(void) {
    long long n, root = 0;
    if (scanf("%lld", &n) != 1) return 1;
    while ((root + 1) * (root + 1) <= n) root++;
    printf("%s\n", root * root == n ? "Perfect Square" : "Not Perfect Square");
    return 0;
}
