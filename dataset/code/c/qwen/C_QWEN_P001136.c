#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a = 0, b = 1, c = 1;
    for(int i=0; i<n; i++) { long long t = a + b + c; a = b; b = c; c = t; }
    printf("%lld\n", n == 0 ? 0 : (n <= 2 ? 1 : a));
    return 0;
}
