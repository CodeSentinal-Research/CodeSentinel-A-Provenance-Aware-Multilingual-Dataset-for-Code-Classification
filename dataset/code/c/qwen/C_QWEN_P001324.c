#include <stdio.h>

int k, n;
int cur[10];

void gen(int i, int sum, int st) {
    if (i == k) {
        if (sum == n) {
            for (int j = 0; j < k; j++) printf("%d ", cur[j]);
            printf("\n");
        }
        return;
    }
    for (int x = st; x <= 9; x++) {
        cur[i] = x;
        gen(i + 1, sum + x, x + 1);
    }
}

int main() {
    scanf("%d%d", &k, &n);
    gen(0, 0, 1);
    return 0;
}
