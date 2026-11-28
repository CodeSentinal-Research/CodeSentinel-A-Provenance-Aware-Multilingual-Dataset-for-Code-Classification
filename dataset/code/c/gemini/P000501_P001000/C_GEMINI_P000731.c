#include <stdio.h>
#include <stdbool.h>
bool cols[32], d1[64], d2[64];
int total_count = 0;
void backtrack(int n, int r) {
    if (r == n) { total_count++; return; }
    for (int c = 0; c < n; c++) {
        if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
        cols[c] = d1[r + c] = d2[r - c + n] = true;
        backtrack(n, r + 1);
        cols[c] = d1[r + c] = d2[r - c + n] = false;
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        backtrack(n, 0);
        printf("%d\n", total_count);
    }
    return 0;
}