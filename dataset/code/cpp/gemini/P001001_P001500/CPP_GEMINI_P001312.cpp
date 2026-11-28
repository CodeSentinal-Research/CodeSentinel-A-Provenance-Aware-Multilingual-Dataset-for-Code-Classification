#include <vector>

class Solution {
    std::vector<bool> cols, posDiag, negDiag;

    int backtrack(int r, int n) {
        if (r == n) return 1;
        int count = 0;
        for (int c = 0; c < n; c++) {
            if (cols[c] || posDiag[r + c] || negDiag[r - c + n]) continue;
            cols[c] = true; posDiag[r + c] = true; negDiag[r - c + n] = true;

            count += backtrack(r + 1, n);

            cols[c] = false; posDiag[r + c] = false; negDiag[r - c + n] = false;
        }
        return count;
    }
public:
    int totalNQueens(int n) {
        cols.assign(n, false);
        posDiag.assign(2 * n, false);
        negDiag.assign(2 * n, false);
        return backtrack(0, n);
    }
};