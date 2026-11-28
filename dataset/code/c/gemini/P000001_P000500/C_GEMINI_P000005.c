#include <stdio.h>

int main(void) {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int a, b;
            if (scanf("%d %d", &a, &b) == 2) {
                printf("%d\n", a % b);
            }
        }
    }
    return 0;
}