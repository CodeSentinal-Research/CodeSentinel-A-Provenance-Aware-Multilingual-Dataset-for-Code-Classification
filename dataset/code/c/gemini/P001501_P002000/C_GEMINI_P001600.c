#include <stdio.h>

int main() {
    int n, l, r;
    if (scanf("%d %d %d", &n, &l, &r) == 3) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i >= l && i <= r) sum += x;
        }
        printf("%.2f\n", sum / (r - l + 1));
    }
    return 0;
}