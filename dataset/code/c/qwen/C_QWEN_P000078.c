#include <stdio.h>

int main() {
    int d;
    scanf("%d", &d);
    printf("%d %d %d\n", d / 365, (d % 365) / 7, d % 7);
    return 0;
}
