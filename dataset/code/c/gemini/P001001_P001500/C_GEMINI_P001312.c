#include <stdbool.h>

bool cols[30], posDiag[60], negDiag[60];

int backtrackQueens(int r, int n) {
    if (r == n) return 1;
    int count = 0;
    for (int c = 0; c < n; c++) {
        if (cols[c] || posDiag[r + c] || negDiag[r - c + n]) continue;
        cols[c] = true; posDiag[r + c] = true; negDiag[r - c + n] = true;

        count += backtrackQueens(r + 1, n);

        cols[c] = false; posDiag[r + c] = false; negDiag[r - c + n] = false;
    }
    return count;
}

int totalNQueens(int n) {
    for (int i = 0; i < 30; i++) cols[i] = false;
    for (int i = 0; i < 60; i++) { posDiag[i] = false; negDiag[i] = false; }
    return backtrackQueens(0, n);
}