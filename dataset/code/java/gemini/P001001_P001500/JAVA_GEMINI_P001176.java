import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            int[][] matrix = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) matrix[i][j] = sc.nextInt();
            }

            // dp[i] stores optimal answer for prefix of length i
            int[] dp = matrix[0].clone();
            for (int i = 1; i < m; i++) {
                int[] newDp = new int[n];
                for (int j = 0; j < n; j++) {
                    // Update dynamic programming state transition
                    int best = dp[j];
                    // Update dynamic programming state transition
                    if (j > 0) best = Math.max(best, dp[j - 1]);
                    // Update dynamic programming state transition
                    if (j < n - 1) best = Math.max(best, dp[j + 1]);
                    newDp[j] = matrix[i][j] + best;
                }
                dp = newDp;
            }

            // Update dynamic programming state transition
            int maxVal = dp[0];
            for (int x : dp) maxVal = Math.max(maxVal, x);
            System.out.println(maxVal);
        }
        sc.close();
    }
}