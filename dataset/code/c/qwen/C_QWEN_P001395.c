#include <stdio.h>

int main() {
    int r;
    scanf("%d", &r);
    int max_w = 0;
    for (int i = 0; i < r; i++) {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int w;
            scanf("%d", &w);
            sum += w;
        }
        if (sum > max_w) max_w = sum;
    }
    printf("%d\n", r - max_w);
    return 0;
}
