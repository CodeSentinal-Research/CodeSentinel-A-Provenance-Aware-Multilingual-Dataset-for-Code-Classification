import java.util.*;

public class Solution {
    private List<List<String>> res = new ArrayList<>();
    private boolean[] cols, posDiag, negDiag;

    private void backtrack(int r, int n, char[][] board) {
        if (r == n) {
            List<String> list = new ArrayList<>();
            for (int i = 0; i < n; i++) list.add(new String(board[i]));
            res.add(list);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols[c] || posDiag[r + c] || negDiag[r - c + n]) continue;
            cols[c] = true; posDiag[r + c] = true; negDiag[r - c + n] = true;
            board[r][c] = 'Q';

            backtrack(r + 1, n, board);

            cols[c] = false; posDiag[r + c] = false; negDiag[r - c + n] = false;
            board[r][c] = '.';
        }
    }

    public List<List<String>> solveNQueens(int n) {
        cols = new boolean[n];
        posDiag = new boolean[2 * n];
        negDiag = new boolean[2 * n];
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(board[i], '.');

        backtrack(0, n, board);
        return res;
    }
}