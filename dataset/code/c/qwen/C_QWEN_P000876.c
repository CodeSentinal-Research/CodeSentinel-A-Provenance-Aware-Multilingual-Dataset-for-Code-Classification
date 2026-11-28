#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mask = 1; while(mask <= n) mask <<= 1; mask--;
    printf("%d\n", n ^ mask);
    return 0;
}
