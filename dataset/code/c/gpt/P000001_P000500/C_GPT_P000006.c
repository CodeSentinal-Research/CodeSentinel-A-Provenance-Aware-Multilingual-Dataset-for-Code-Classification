#include <stdio.h>

int main(void) {
    int a, b, temp;

    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }

    temp = a;
    a = b;
    b = temp;
    printf("%d %d\n", a, b);

    return 0;
}
