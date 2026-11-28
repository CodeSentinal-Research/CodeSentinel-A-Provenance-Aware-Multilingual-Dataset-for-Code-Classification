#include <stdio.h>

int n;
int ans = 0;
int used[16];

void gen(int i) {
    if (i == n) {
        ans++;
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (!used[x] && (x % i == 0 || i % x == 0)) {
            used[x] = 1;
            gen(i + 1);
            used[x] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    gen(1);
    printf("%d\n", ans);
    return 0;
}
