#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    if(n==0) { printf("1\n"); return 0; }
    int mask = 1;
    while(mask <= n) mask <<= 1;
    mask--;
    printf("%d\n", n ^ mask);
    return 0;
}
