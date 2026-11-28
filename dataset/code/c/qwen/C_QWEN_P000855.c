#include <stdio.h>
int main() {
    unsigned int n; scanf("%u", &n);
    int count = 0;
    if(n==0) count=32;
    else { while(!(n & (1u << 31))) { count++; n <<= 1; } }
    printf("%d\n", count);
    return 0;
}
