#include <stdio.h>
int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int max_v = -2000000000;
        for (int i = 0; i < r * c; i++) {
            int v;
            scanf("%d", &v);
            if (v > max_v) max_v = v;
        }
        printf("%d\n", max_v);
    }
    return 0;
}