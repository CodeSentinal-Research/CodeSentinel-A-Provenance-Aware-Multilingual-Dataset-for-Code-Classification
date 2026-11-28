#include <stdio.h>
int main() {
    unsigned int n; scanf("%u", &n);
    unsigned int res = 0;
    for(int i=0; i<32; i++) { res = (res << 1) | (n & 1); n >>= 1; }
    printf("%u\n", res);
    return 0;
}
