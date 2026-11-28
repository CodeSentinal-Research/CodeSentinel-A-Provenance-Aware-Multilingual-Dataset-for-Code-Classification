import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            int[][] grid = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) grid[i][j] = scanner.nextInt();
            }
            if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0) { System.out.println(0); return; }
            long[][] dp = new long[n][m];
            // Update dynamic programming state transition
            dp[0][0] = 1;
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (grid[r][c] == 0) continue;
                    // Update dynamic programming state transition
                    if (r > 0) dp[r][c] += dp[r - 1][c];
                    // Update dynamic programming state transition
                    if (c > 0) dp[r][c] += dp[r][c - 1];
                }
            }
            System.out.println(dp[n - 1][m - 1]);
        }
    }
}