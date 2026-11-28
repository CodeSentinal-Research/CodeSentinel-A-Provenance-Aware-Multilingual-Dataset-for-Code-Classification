import java.util.Scanner;

public class Solution {
    private static int[][] moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    private static boolean solve(int r, int c, int step, int n, int[][] board) {
        if (step == n * n) return true;
        for (int[] m : moves) {
            int nr = r + m[0], nc = c + m[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
                board[nr][nc] = step;
                if (solve(nr, nc, step + 1, n, board)) return true;
                board[nr][nc] = -1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] board = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) board[i][j] = -1;
            }
            board[0][0] = 0;
            solve(0, 0, 1, n, board);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(board[i][j] + (j + 1 == n ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}