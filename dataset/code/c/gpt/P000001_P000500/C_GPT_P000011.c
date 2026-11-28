#include <stdio.h>

int main(void) {
    int a, b, c;

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }

    int max;
    if (a >= b) {
        if (a >= c) max = a;
        else max = c;
    } else {
        if (b >= c) max = b;
        else max = c;
    }
    printf("%d\n", max);

    return 0;
}
