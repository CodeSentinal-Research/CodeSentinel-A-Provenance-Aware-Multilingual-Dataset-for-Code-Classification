#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int count = 0;
    if(n==0) count=32;
    else { while(!(n & 1)) { count++; n >>= 1; } }
    printf("%d\n", count);
    return 0;
}
