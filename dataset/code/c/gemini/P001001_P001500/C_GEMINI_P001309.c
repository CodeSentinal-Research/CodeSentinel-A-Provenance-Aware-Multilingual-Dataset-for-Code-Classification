#include <stdio.h>

int main() {
    int s, n, m;
    if (scanf("%d %d %d", &s, &n, &m) == 3) {
        int totalFood = s * m;
        if ((n - m) * 6 < m && s > 6) {
            printf("-1\n");
        } else if (m > n) {
            printf("-1\n");
        } else {
            printf("%d\n", (totalFood + n - 1) / n);
        }
    }
    return 0;
}