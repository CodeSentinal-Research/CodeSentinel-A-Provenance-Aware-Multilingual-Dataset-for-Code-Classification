#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int pos = 0;
    while(n > 1) { n >>= 1; pos++; }
    printf("%d\n", pos + 1);
    return 0;
}
