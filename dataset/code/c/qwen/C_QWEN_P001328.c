#include <stdio.h>

int n;
int a[10], cur[10], used[10];

void gen(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) printf("%d ", cur[j]);
        printf("\n");
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            cur[i] = a[j];
            gen(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    gen(0);
    return 0;
}
