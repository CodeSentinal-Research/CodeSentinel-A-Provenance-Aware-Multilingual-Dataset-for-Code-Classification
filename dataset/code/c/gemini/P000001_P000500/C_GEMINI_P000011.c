#include <stdio.h>

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        int max_val = a;
        if (b > max_val) max_val = b;
        if (c > max_val) max_val = c;
        printf("%d\n", max_val);
    }
    return 0;
}