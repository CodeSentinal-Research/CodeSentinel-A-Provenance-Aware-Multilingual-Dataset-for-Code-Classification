import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            int[][] cost = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) cost[i][j] = sc.nextInt();
            }

            int[][] dp = new int[m][n];
            // Update dynamic programming state transition
            dp[0][0] = cost[0][0];
            for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];
            for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    // Update dynamic programming state transition
                    dp[i][j] = cost[i][j] + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
            System.out.println(dp[m - 1][n - 1]);
        }
        sc.close();
    }
}