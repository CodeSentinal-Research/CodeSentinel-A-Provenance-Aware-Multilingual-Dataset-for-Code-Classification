public class Solution {
    private boolean[] cols, posDiag, negDiag;

    private int backtrack(int r, int n) {
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

    public int totalNQueens(int n) {
        cols = new boolean[n];
        posDiag = new boolean[2 * n];
        negDiag = new boolean[2 * n];
        return backtrack(0, n);
    }
}