#include <stdio.h>

int n, t;
int a[30], cur[30];

void gen(int i, int sum) {
    if (sum == t) {
        for (int j = 0; j < i; j++) printf("%d ", cur[j]);
        printf("\n");
        return;
    }
    if (i >= n || sum > t) return;
    cur[i] = a[i];
    gen(i + 1, sum + a[i]);
    gen(i + 1, sum);
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    gen(0, 0);
    return 0;
}
