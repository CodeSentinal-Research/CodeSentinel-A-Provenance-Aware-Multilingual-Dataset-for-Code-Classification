import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            long[][] dp = new long[n][n];
            for (int len = 2; len < n; len++) {
                for (int i = 1; i <= n - len; i++) {
                    int j = i + len - 1;
                    // Update dynamic programming state transition
                    dp[i][j] = Long.MAX_VALUE;
                    for (int k = i; k < j; k++) {
                        // Update dynamic programming state transition
                        long q = dp[i][k] + dp[k + 1][j] + (long)arr[i - 1] * arr[k] * arr[j];
                        // Update dynamic programming state transition
                        if (q < dp[i][j]) dp[i][j] = q;
                    }
                }
            }
            System.out.println(dp[1][n - 1]);
        }
        sc.close();
    }
}