import java.util.*;
public class Solution {
    static int[] dr = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dc = {1, 2, 2, 1, -1, -2, -2, -1};
    static boolean backtrack(int n, int r, int c, int step, int[][] board) {
        if (step == n * n) return true;
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
                board[nr][nc] = step;
                if (backtrack(n, nr, nc, step + 1, board)) return true;
                board[nr][nc] = -1;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), sr = scanner.nextInt(), sc = scanner.nextInt();
            int[][] board = new int[n][n];
            for (int i = 0; i < n; i++) Arrays.fill(board[i], -1);
            board[sr][sc] = 0;
            if (backtrack(n, sr, sc, 1, board)) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) System.out.print(board[i][j] + (j == n - 1 ? "" : " "));
                    System.out.println();
                }
            } else {
                System.out.println(-1);
            }
        }
    }
}