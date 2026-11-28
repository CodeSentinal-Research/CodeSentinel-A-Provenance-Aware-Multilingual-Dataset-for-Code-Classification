import java.util.*;
public class Solution {
    static void backtrack(int n, int r, char[][] board, boolean[] cols, boolean[] d1, boolean[] d2) {
        if (r == n) {
            for (int i = 0; i < n; i++) System.out.println(new String(board[i]));
            System.out.println();
            return;
        }
        for (int c = 0; c < n; c++) {
            if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
            cols[c] = d1[r + c] = d2[r - c + n] = true;
            board[r][c] = 'Q';
            backtrack(n, r + 1, board, cols, d1, d2);
            board[r][c] = '.';
            cols[c] = d1[r + c] = d2[r - c + n] = false;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            char[][] board = new char[n][n];
            for (int i = 0; i < n; i++) Arrays.fill(board[i], '.');
            backtrack(n, 0, board, new boolean[n], new boolean[2 * n], new boolean[2 * n]);
        }
    }
}