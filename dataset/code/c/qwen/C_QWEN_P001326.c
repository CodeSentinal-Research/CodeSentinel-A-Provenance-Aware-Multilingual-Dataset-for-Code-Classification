#include <stdio.h>

int n;
int a[20], cur[20];

void gen(int i, int j) {
    if (i == n) {
        printf("[");
        for (int x = 0; x < j; x++) printf("%d ", cur[x]);
        printf("]\n");
        return;
    }
    cur[j] = a[i];
    gen(i + 1, j + 1);
    gen(i + 1, j);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    gen(0, 0);
    return 0;
}
