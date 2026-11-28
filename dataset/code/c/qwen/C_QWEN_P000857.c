#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    printf("%s\n", (n > 0 && (n & (n - 1)) == 0) ? "true" : "false");
    return 0;
}
