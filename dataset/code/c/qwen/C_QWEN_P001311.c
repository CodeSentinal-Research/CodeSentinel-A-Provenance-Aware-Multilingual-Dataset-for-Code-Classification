#include <stdio.h>

int n;
int ans = 0;
int col[15], d1[30], d2[30];

void solve(int r) {
    if (r == n) {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !d1[r + c] && !d2[r - c + n]) {
            col[c] = d1[r + c] = d2[r - c + n] = 1;
            solve(r + 1);
            col[c] = d1[r + c] = d2[r - c + n] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    solve(0);
    printf("%d\n", ans);
    return 0;
}
