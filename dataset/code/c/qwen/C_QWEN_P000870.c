#include <stdio.h>
int main() {
    int a, b; scanf("%d%d", &a, &b);
    while(b) { int carry = a & b; a ^= b; b = carry << 1; }
    printf("%d\n", a);
    return 0;
}
