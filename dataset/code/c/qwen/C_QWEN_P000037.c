#include <stdio.h>

int main() {
    char b[32];
    long long d = 0;
    scanf("%s", b);
    for (int i = 0; b[i]; i++) d = d * 2 + (b[i] - '0');
    printf("%lld\n", d);
    return 0;
}
