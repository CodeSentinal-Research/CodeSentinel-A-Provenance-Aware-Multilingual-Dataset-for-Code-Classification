#include <stdio.h>

int n, k;
int cur[20];

void gen(int i, int st) {
    if (i == k) {
        for (int j = 0; j < k; j++) printf("%d ", cur[j]);
        printf("\n");
        return;
    }
    for (int x = st; x <= n; x++) {
        cur[i] = x;
        gen(i + 1, x + 1);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    gen(0, 1);
    return 0;
}
