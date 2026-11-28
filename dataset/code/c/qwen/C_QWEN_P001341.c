#include <stdio.h>

int n, k;
int a[20], cur[20];

void gen(int i, int j, int last) {
    if (j == k) {
        for (int x = 0; x < k; x++) printf("%d ", cur[x]);
        printf("\n");
        return;
    }
    for (int x = i; x < n; x++) {
        if (a[x] > last) {
            cur[j] = a[x];
            gen(x + 1, j + 1, a[x]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    gen(0, 0, -1);
    return 0;
}
