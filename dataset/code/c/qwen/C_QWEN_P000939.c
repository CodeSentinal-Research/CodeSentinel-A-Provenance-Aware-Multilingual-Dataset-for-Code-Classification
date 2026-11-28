#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    printf("%s\n", n % 4 != 0 ? "true" : "false");
    return 0;
}
