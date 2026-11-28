#include <stdio.h>
#include <string.h>

char b[9][10];

int ok(int r, int c, char v) {
    for (int i = 0; i < 9; i++) {
        if (b[r][i] == v || b[i][c] == v) return 0;
    }
    int br = r / 3 * 3, bc = c / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[br + i][bc + j] == v) return 0;
        }
    }
    return 1;
}

int solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (b[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (ok(i, j, c)) {
                        b[i][j] = c;
                        if (solve()) return 1;
                        b[i][j] = '.';
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    for (int i = 0; i < 9; i++) scanf("%s", b[i]);
    solve();
    for (int i = 0; i < 9; i++) printf("%s\n", b[i]);
    return 0;
}
