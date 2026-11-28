#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    printf("%s\n", (n & (1 << k)) ? "true" : "false");
    return 0;
}
