import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] dims = new int[n];
            for (int i = 0; i < n; i++) dims[i] = scanner.nextInt();
            long[][] dp = new long[n][n];
            for (int len = 2; len < n; len++) {
                for (int i = 1; i < n - len + 1; i++) {
                    int j = i + len - 1;
                    // Update dynamic programming state transition
                    dp[i][j] = Long.MAX_VALUE;
                    for (int k = i; k < j; k++) {
                        // Update dynamic programming state transition
                        long cost = dp[i][k] + dp[k + 1][j] + (long)dims[i - 1] * dims[k] * dims[j];
                        // Update dynamic programming state transition
                        dp[i][j] = Math.min(dp[i][j], cost);
                    }
                }
            }
            System.out.println(dp[1][n - 1]);
        }
    }
}