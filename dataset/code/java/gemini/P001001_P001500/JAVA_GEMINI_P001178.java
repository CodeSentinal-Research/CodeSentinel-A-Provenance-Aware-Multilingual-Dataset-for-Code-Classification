import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            int[][] mine = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) mine[i][j] = sc.nextInt();
            }

            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) dp[i][0] = mine[i][0];

            for (int j = 1; j < n; j++) {
                for (int i = 0; i < m; i++) {
                    // Update dynamic programming state transition
                    int best = dp[i][j - 1];
                    // Update dynamic programming state transition
                    if (i > 0) best = Math.max(best, dp[i - 1][j - 1]);
                    // Update dynamic programming state transition
                    if (i < m - 1) best = Math.max(best, dp[i + 1][j - 1]);
                    // Update dynamic programming state transition
                    dp[i][j] = mine[i][j] + best;
                }
            }

            int ans = 0;
            for (int i = 0; i < m; i++) ans = Math.max(ans, dp[i][n - 1]);
            System.out.println(ans);
        }
        sc.close();
    }
}