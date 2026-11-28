#include <stdio.h>

int n;
int a[30];
int min_diff = 1000000000;

void gen(int i, int s1, int s2, int c1, int c2) {
    if (i == n) {
        if (c1 == c2 || c1 == c2 + 1 || c2 == c1 + 1) {
            int d = s1 > s2 ? s1 - s2 : s2 - s1;
            if (d < min_diff) min_diff = d;
        }
        return;
    }
    gen(i + 1, s1 + a[i], s2, c1 + 1, c2);
    gen(i + 1, s1, s2 + a[i], c1, c2 + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    gen(0, 0, 0, 0, 0);
    printf("%d\n", min_diff);
    return 0;
}
