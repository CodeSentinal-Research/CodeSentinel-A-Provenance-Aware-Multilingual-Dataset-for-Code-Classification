#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%s\n", (n % (k + 1) != 0) ? "FIRST" : "SECOND");
    return 0;
}
